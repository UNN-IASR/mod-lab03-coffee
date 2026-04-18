// Copyright 2024 GHA Test Team

#include "Automata.h"
#include <iostream>

Automata::Automata() : cash(0), selected(-1), state(STATES::OFF) {
    menu   = {"Кофе", "Чай", "Молоко", "Какао"};
    prices = {50,     30,    20,       40};
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        std::cout << "[on] Автомат включён. Ожидание.\n";
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        std::cout << "[off] Автомат выключен.\n";
    }
}

void Automata::coin(int amount) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        cash += amount;
        state = STATES::ACCEPT;
        std::cout << "[coin] Внесено " << amount
                  << " руб. Итого: " << cash << " руб.\n";
    }
}

void Automata::getMenu() const {
    if (state == STATES::ACCEPT) {
        std::cout << "[menu] Меню напитков:\n";
        for (int i = 0; i < static_cast<int>(menu.size()); ++i)
            std::cout << "  " << i + 1 << ". " << menu[i]
                      << " — " << prices[i] << " руб.\n";
    }
}

STATES Automata::getState() const {
    return state;
}

void Automata::choice(int item) {
    if (state == STATES::ACCEPT) {
        int idx = item - 1;
        if (idx >= 0 && idx < static_cast<int>(menu.size())) {
            selected = idx;
            state = STATES::SELECT;
            std::cout << "[choice] Выбран напиток: " << menu[idx] << "\n";
            check();
        } else {
            std::cout << "[choice] Неверный номер напитка.\n";
        }
    }
}

void Automata::check() {
    if (state == STATES::SELECT) {
        state = STATES::CHECK;
        if (cash >= prices[selected]) {
            std::cout << "[check] Сумма достаточна. Готовлю напиток...\n";
            cook();
        } else {
            std::cout << "[check] Недостаточно средств. Нужно ещё "
                      << prices[selected] - cash << " руб.\n";
            state = STATES::ACCEPT;
        }
    }
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::SELECT
            || state == STATES::CHECK) {
        std::cout << "[cancel] Сеанс отменён. Возврат: " << cash << " руб.\n";
        cash = 0;
        selected = -1;
        state = STATES::WAIT;
    }
}

void Automata::cook() {
    if (state == STATES::CHECK) {
        state = STATES::COOK;
        cash -= prices[selected];
        std::cout << "[cook] Приготовление напитка...\n";
        state = STATES::DONE;
        finish();
    }
}

void Automata::finish() {
    if (state == STATES::DONE) {
        std::cout << "[finish] Напиток готов! Сдача: " << cash << " руб.\n";
        cash = 0;
        selected = -1;
        state = STATES::WAIT;
    }
}
