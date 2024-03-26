// Copyright 2024 Kokorin Alexandr

#include "Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    menu = {"Чай", "Кофе", "Молоко", "Какао", "Горячий шоколад"};
    prices = {5, 15, 8, 10, 12};
    state = OFF;
}

Automata::~Automata() {}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "Автомат включился." << std::endl;
    } else {
        std::cout << "Автомат уже включён." << std::endl;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "Автомат выключился." << std::endl;
    } else if (state == OFF) {
        std::cout << "Автомат уже выключён." << std::endl;
    } else {
        std::cout << "Автомат не завершил свою работу." << std::endl;
    }
}

void Automata::coin(int sum) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += sum;
        std::cout << "Деньги внесены: "<< sum << std::endl;
    } else {
        std::cout << "Дождитесь завершения работы автомата." << std::endl;
    }
}

void Automata::getMenu() {
    std::cout << " Меню:--------------------------------------- " << std::endl;
    for (int i = 0; i < menu.size(); i++) {
        std::cout << menu[i] << " - " << prices[i] << std::endl;
    }
    std::cout << " -------------------------------------------- " << std::endl;
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int num) {
    if (state == ACCEPT) {
        state = CHECK;
        std::cout << "Выбор сделан: " << num << std::endl;
    } else {
        std::cout << "Внесите деньги и выберите напиток." << std::endl;
    }
}

void Automata::check(int num) {
    if (state == CHECK) {
        if (prices[num-1] <= cash) {
            state = CHECK;
            std::cout << "Все деньги успешно внесены." << std::endl;
        } else {
            std::cout << "Недостаточно денег на счете, внесите до нужной суммы."
            << " ( " << cash << "из" << prices[num-1] << " )"<< std::endl;
        }
    } else {
        std::cout << "Внесите деньги и выберите напиток." << std::endl;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state ==CHECK) {
        state = WAIT;
        std::cout << "Операция прервана." << std::endl;
    } else {
        std::cout << "Дождитесь завершения работы автомата." << std::endl;
    }
}

void Automata::cook(int num) {
    if (state == CHECK && cash >= prices[num-1]) {
        state = COOK;
        std::cout << "Приготовление напитка..." << menu[num-1]
        << std::endl; cash -= prices[num-1];
    } else {
        std::cout << "Внесите деньги и выберите напиток." << std::endl;
    }
}

void Automata::finish() {
    if (state == COOK) {
        state = WAIT;
        std::cout << "Напиток готов. Приятного аппетита." << std::endl;
    } else {
        std::cout << "Дождитесь завершения работы автомата." << std::endl;
    }
}
