// Copyright 2024 UNN-IASR
#include "../include/Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    state = STATES::OFF;
    // Базовое меню
    menu = { "Эспрессо", "Американо", "Капучино", "Латте" };
    prices = { 50, 60, 100, 120 };
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        std::cout << "Кофемашина включена. Ожидание..." << std::endl;
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        std::cout << "Кофемашина выключена." << std::endl;
    }
}

void Automata::coin(int amount) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        state = STATES::ACCEPT;
        cash += amount;
        std::cout << "Внесено: " << amount
            << " руб. Баланс: " << cash << " руб." << std::endl;
    }
}

void Automata::getMenu() const {
    std::cout << "\n--- Меню напитков ---" << std::endl;
    for (size_t i = 0; i < menu.size(); ++i) {
        std::cout << i + 1 << ". " << menu[i]
            << " - " << prices[i] << " руб." << std::endl;
    }
    std::cout << "---------------------\n" << std::endl;
}

STATES Automata::getState() const {
    return state;
}

void Automata::choice(int index) {
    if (state == STATES::ACCEPT) {
        state = STATES::CHECK;
        if (index > 0 && index <= menu.size()) {
            std::cout << "Выбран напиток: " << menu[index - 1]
                << ". Проверка средств..." << std::endl;
        } else {
            std::cout << "Неверный выбор напитка!" << std::endl;
            cancel();
        }
    } else {
        std::cout << "Ошибка: сначала внесите деньги." << std::endl;
    }
}

bool Automata::check(int index) {
    if (state == STATES::CHECK) {
        if (index > 0 && index <= menu.size() && cash >= prices[index - 1]) {
            return true;
        } else {
            std::cout << "Недостаточно средств для этого напитка!" << std::endl;
            return false;
        }
    }
    return false;
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        state = STATES::WAIT;
        std::cout << "Отмена операции. Возврат средств: "
            << cash << " руб." << std::endl;
        cash = 0;
    }
}

void Automata::cook(int index) {
    if (state == STATES::CHECK) {
        if (check(index)) {
            state = STATES::COOK;
            cash -= prices[index - 1];
            std::cout << "Приготовление " << menu[index - 1]
                << "..." << std::endl;
        } else {
            cancel();
        }
    }
}

void Automata::finish() {
    if (state == STATES::COOK) {
        state = STATES::WAIT;
        std::cout << "Напиток готов! Заберите сдачу: "
            << cash << " руб." << std::endl;
        cash = 0;
    }
}
