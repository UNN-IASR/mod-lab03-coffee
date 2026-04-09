// Copyright 2026
#include "Automata.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
Automata::Automata() : cash(0), state(STATES::OFF), selectedItem(-1) {
    menu = {"Чай", "Кофе", "Какао", "Молоко"};
    prices = {30, 50, 40, 25};
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        cash = 0;
        selectedItem = -1;
        std::cout << "Автомат включён. Состояние: ОЖИДАНИЕ\n";
    } else {
        std::cout << "Нельзя включить – автомат уже не в состоянии OFF\n";
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        cash = 0;
        selectedItem = -1;
        std::cout << "Автомат выключен.\n";
    } else {
        std::cout << "Выключение возможно только из состояния ОЖИДАНИЕ\n";
    }
}

void Automata::coin(int amount) {
    if (state == STATES::WAIT) {
        state = STATES::ACCEPT;
        cash += amount;
        std::cout << "Внесено " << amount << " руб. Переход в ПРИЁМ ДЕНЕГ\n";
    } else if (state == STATES::ACCEPT) {
        cash += amount;
        std::cout << "Внесено " << amount << " руб. Баланс: " << cash << " руб.\n";
    } else {
        std::cout << "Монету можно внести только в состояниях ОЖИДАНИЕ или ПРИЁМ ДЕНЕГ\n";
    }
}

std::string Automata::getMenu() const {
    std::stringstream ss;
    ss << "Меню:\n";
    for (size_t i = 0; i < menu.size(); ++i) {
        ss << i + 1 << ". " << menu[i] << " - " << prices[i] << " руб.\n";
    }
    return ss.str();
}

std::string Automata::getState() const {
    switch (state) {
        case STATES::OFF:    return "OFF (Выключен)";
        case STATES::WAIT:   return "WAIT (Ожидание)";
        case STATES::ACCEPT: return "ACCEPT (Приём денег)";
        case STATES::CHECK:  return "CHECK (Проверка средств)";
        case STATES::COOK:   return "COOK (Приготовление)";
        default:             return "UNKNOWN";
    }
}

void Automata::choice(int index) {
    if (state != STATES::ACCEPT) {
        std::cout << "Выбор напитка возможен только в состоянии ПРИЁМ ДЕНЕГ\n";
        return;
    }
    if (index < 0 || index >= static_cast<int>(menu.size())) {
        std::cout << "Неверный номер напитка\n";
        return;
    }
    selectedItem = index;
    state = STATES::CHECK;
    std::cout << "Выбран напиток: " << menu[selectedItem] << " (" << prices[selectedItem] << " руб.)\n";
}

bool Automata::check() {
    if (state != STATES::CHECK) {
        std::cout << "Проверка возможна только в состоянии CHECK\n";
        return false;
    }
    if (selectedItem == -1) {
        std::cout << "Напиток не выбран\n";
        state = STATES::ACCEPT;
        return false;
    }
    if (cash >= prices[selectedItem]) {
        std::cout << "Средств достаточно. Начинаем приготовление...\n";
        state = STATES::COOK;
        return true;
    } else {
        std::cout << "Недостаточно средств. Нужно ещё " << (prices[selectedItem] - cash) << " руб.\n";
        state = STATES::ACCEPT;
        return false;
    }
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        std::cout << "Отмена сеанса. Возврат " << cash << " руб.\n";
        cash = 0;
        selectedItem = -1;
        state = STATES::WAIT;
    } else if (state == STATES::WAIT) {
        std::cout << "Нет активного сеанса для отмены\n";
    } else {
        std::cout << "Отмена невозможна в текущем состоянии\n";
    }
}

void Automata::cook() {
    if (state != STATES::COOK) {
        std::cout << "Приготовление возможно только в состоянии COOK\n";
        return;
    }
    std::cout << "Готовим " << menu[selectedItem] << "... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Готово!\n";
}

void Automata::finish() {
    if (state != STATES::COOK) {
        std::cout << "Завершение возможно только в состоянии COOK\n";
        return;
    }
    cash -= prices[selectedItem];
    std::cout << "Выдан " << menu[selectedItem] << ". Сдача: " << cash << " руб.\n";
    cash = 0;
    selectedItem = -1;
    state = STATES::WAIT;
    std::cout << "Автомат вернулся в состояние ОЖИДАНИЕ\n";
}