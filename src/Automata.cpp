// Copyright 2026 Belev Timur
#include "Automata.h"
#include <iostream>
#include <sstream>
#include <string>

Automata::Automata() : cash(0.0), state(State::OFF), selectedPrice(0.0) {
    loadMenu();
}

void Automata::on() {
    if (state == State::OFF) {
        state = State::WAIT;
        std::cout << "Автомат включен. Состояние: ОЖИДАНИЕ" << std::endl;
    } else {
        std::cout << "Автомат уже включен!" << std::endl;
    }
}

void Automata::off() {
    if (state == State::WAIT) {
        state = State::OFF;
        std::cout << "Автомат выключен." << std::endl;
    } else if (state == State::OFF) {
        std::cout << "Автомат уже выключен!" << std::endl;
    } else {
        std::cout << "Идёт обслуживание!" << std::endl;
    }
}

void Automata::coin(double amount) {
    if (amount <= 0) {
        std::cout << "Ошибка: сумма должна быть положительной!" << std::endl;
        return;
    }
    if (state == State::WAIT) {
        cash = amount;
        state = State::ACCEPT;
        std::cout << "Внесено: " << amount << " руб" << std::endl;
    } else if (state == State::ACCEPT) {
        cash += amount;
        std::cout << "Добавлено: " << amount << " руб.<< std::endl;
    } else {
        std::cout << "Невозможно внести" << std::endl;
    }
}

Automata::getMenu() {
    if (state == State::OFF) {
        return "Автомат выключен. Включите автомат для просмотра меню.";
    }
    std::stringstream ss;
    ss << "\n========== МЕНЮ ==========\n";
    for (size_t i = 0; i < menu.size(); ++i) {
        ss << i + 1 << ". " << menu[i] << " - " << prices[i] << " руб.\n";
    }
    ss << "==========================\n";
    return ss.str();
}

State Automata::getState() {
    return state;
}

bool Automata::choice(int index) {
    if (state != State::ACCEPT) {
        std::cout << "Автомат не в режиме приёма денег!" << std::endl;
        return false;
    }
    if (index < 1 || index > static_cast<int>(menu.size())) {
        std::cout << "Неверный номер напитка!" << std::endl;
        return false;
    }
    selectedDrink = menu[index - 1];
    selectedPrice = prices[index - 1];
    state = State::CHECK;
    std::cout << "Выбран напиток: " << selectedDrink << " (" << selectedPrice << " руб.)" << std::endl;
    std::cout << "Состояние: ПРОВЕРКА НАЛИЧНОСТИ" << std::endl;
    return true;
}
bool Automata::check() {
    if (state != State::CHECK) {
        std::cout << "Ошибка: автомат не в состоянии проверки!" << std::endl;
        return false;
    }  
    if (cash >= selectedPrice) {
        std::cout << "Суммы достаточно. Начинаем приготовление..." << std::endl;
        return true;
    } else {
        std::cout << "Недостаточно средств! Нужно: " << selectedPrice 
                  << " руб. Внесено: " << cash << " руб." << std::endl;
        return false;
    }
}
void Automata::cancel() {
    if (state == State::ACCEPT) {
        std::cout << "Операция отменена.<< std::endl;
        cash = 0.0;
        state = State::WAIT;
        std::cout << "Состояние: ОЖИДАНИЕ" << std::endl;
    } else if (state == State::CHECK) {
        std::cout << "Операция отменена.<< std::endl;
        cash = 0.0;
        selectedDrink.clear();
        selectedPrice = 0.0;
        state = State::WAIT;
        std::cout << "Состояние: ОЖИДАНИЕ" << std::endl;
    } else if (state == State::WAIT) {
        std::cout << "Нет операции для отмены!" << std::endl;
    } else {
        std::cout << "Невозможно отменить" << std::endl;
    }
}

void Automata::cook() {
    if (state != State::CHECK) {
        std::cout << "Ошибка: автомат не в состоянии проверки!" << std::endl;
        return;
    }
    if (!check()) {
        cancel();
        return;
    }
    state = State::COOK;
    std::cout << "Приготовление " << selectedDrink << "...\n";
    for (int i = 1; i <= 3; ++i) {
        std::cout << ".";
        for (int j = 0; j < 100000000; ++j) {}
    }
    std::cout << "\n" << selectedDrink << " готов!" << std::endl;
    std::cout << "Состояние: ПРИГОТОВЛЕНИЕ" << std::endl;
}
void Automata::finish() {
    if (state != State::COOK) {
        std::cout << "Ошибка: автомат не в состоянии приготовления!" << std::endl;
        return;
    }
    double change = cash - selectedPrice;
    cash = 0.0;
    selectedDrink.clear();
    selectedPrice = 0.0;
    state = State::WAIT;
    if (change > 0) {
        std::cout << "Выдача сдачи: " << change << " руб." << std::endl;
    }
    std::cout << "Заберите ваш напиток. Спасибо за покупку!" << std::endl;
    std::cout << "Состояние: ОЖИДАНИЕ\n" << std::endl;
}
void Automata::loadMenu() {
    menu = {"Чай", "Кофе", "Капучино", "Латте", "Горячий шоколад", "Молоко"};
    prices = {50.0, 80.0, 120.0, 130.0, 100.0, 60.0};
}
double Automata::getCash() {
    return cash;
}
void Automata::giveChange() {
    if (cash > 0 && (state == State::WAIT || state == State::OFF)) {
        std::cout << "Возврат остатка: " << cash << " руб." << std::endl;
        cash = 0.0;
    }
}
