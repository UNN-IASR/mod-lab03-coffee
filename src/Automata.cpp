#include "Automata.h"
#include <iostream>
#include <sstream>
Automata::Automata() : cash(0), selectedPrice(0), state(STATES::OFF) {
    menu = {"Чай", "Кофе", "Молоко", "Горячий шоколад", "Капучино"};
    prices = {50, 80, 60, 100, 120};
}
void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        std::cout << "Автомат вкл, состояние: ОЖИДАНИЕ\n";
    } else {
        std::cout << "Автомат уже вкл\n";
    }
}
void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        cash = 0;
        selectedPrice = 0;
        std::cout << "Автомат выключен\n";
    } else {
        std::cout << "Нельзя выключить автомат в текущем состоянии\n";
    }
}
void Automata::coin(int amount) {
    if (amount <= 0) {
        std::cout << "Некорректная сумма\n";
        return;
    }
    if (state == STATES::WAIT) {
        cash = amount;
        state = STATES::ACCEPT;
        std::cout << "Внесено " << amount << " руб. Состояние: ПРИЁМ ДЕНЕГ\n";
    } else if (state == STATES::ACCEPT) {
        cash += amount;
        std::cout << "Добавлено " << amount << " руб. Всего: " << cash << " руб.\n";
    } else {
        std::cout << "Сейчас нельзя внести деньги\n";
    }
}
std::string Automata::getMenu() {
    std::stringstream ss;
    ss << "===== МЕНЮ =====\n";
    for (size_t i = 0; i < menu.size(); i++) {
        ss << i + 1 << ". " << menu[i] << " - " << prices[i] << " руб.\n";
    }
    ss << "================\n";
    return ss.str();
}
STATES Automata::getState() {
    return state;
}
bool Automata::choice(int drinkIndex) {
    if (state != STATES::ACCEPT) {
        std::cout << "Нельзя выбрать напиток в текущем состоянии\n";
        return false;
    }
    if (drinkIndex < 1 || drinkIndex > static_cast<int>(menu.size())) {
        std::cout << "Неверный выбор напитка\n";
        return false;
    }
    selectedPrice = prices[drinkIndex - 1];
    std::cout << "Выбран напиток: " << menu[drinkIndex - 1] 
              << " - " << selectedPrice << " руб.\n";
    state = STATES::CHECK;
    std::cout << "Состояние: ПРОВЕРКА НАЛИЧНОСТИ\n";
    if (cash >= selectedPrice) {
        std::cout << "Денег достаточно. Начинаем приготовление...\n";
        cook();
        return true;
    } else {
        std::cout << "Недостаточно средств! Нужно: " << selectedPrice 
                  << " руб. Внесено: " << cash << " руб.\n";
        cancel();
        return false;
    }
}
void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        std::cout << "Сеанс отменён. Возврат " << cash << " руб.\n";
        cash = 0;
        selectedPrice = 0;
        state = STATES::WAIT;
        std::cout << "Состояние: ОЖИДАНИЕ\n";
    } else {
        std::cout << "Нельзя отменить в текущем состоянии\n";
    }
}
void Automata::cook() {
    if (state == STATES::CHECK && cash >= selectedPrice) {
        state = STATES::COOK;
        std::cout << "Приготовление напитка...\n";
        // Имитация процесса приготовления
        for (int i = 3; i > 0; i--) {
            std::cout << i << "...\n";
        }
        std::cout << "Напиток готов!\n";
        finish();
    } else {
        std::cout << "Нельзя приготовить в текущем состоянии\n";
    }
}
void Automata::finish() {
    if (state == STATES::COOK) {
        int change = cash - selectedPrice;
        if (change > 0) {
            std::cout << "Выдан напиток. Сдача: " << change << " руб.\n";
        } else {
            std::cout << "Выдан напиток. Спасибо за покупку!\n";
        }
        cash = 0;
        selectedPrice = 0;
        state = STATES::WAIT;
        std::cout << "Состояние: ОЖИДАНИЕ\n";
    } else {
        std::cout << "Нельзя завершить в текущем состоянии\n";
    }
}


int Automata::getCash() const {
    return cash;
}

int Automata::getSelectedPrice() const {
    return selectedPrice;
}
void Automata::setStateForTest(STATES newState) {
    state = newState;
}
