// Copyright 2022 UNN-IASR
#include "Automata.h"

Automata::Automata() {
    state = OFF;
    cash = 0;
    selectedItem = -1;

    for (int i = 0; i < 4; i++) {
        menu[i] = "Coffee " + std::to_string(i);
        prices[i] = 10 * (i + 1);
    }
}

void Automata::on() {
    state = WAIT;
}

void Automata::off() {
    state = OFF;
}

void Automata::coin(int money) {
    cash += money;
    state = ACCEPT;
}

void Automata::getMenu() {
    for (int i = 0; i < 4; i++) {
        std::cout << menu[i] << "   " << prices[i] << std::endl;
    }
}

Automata::States Automata::getState() {
    return state;
}

void Automata::choice(int item) {
    selectedItem = item;
    state = CHECK;
}

bool Automata::check() {
    if (state != CHECK || selectedItem == -1)
        return false;

    return cash >= prices[selectedItem];
}

void Automata::cancel() {
    if (state == OFF)
        return;

    state = WAIT;
    cash = 0;
}

void Automata::cook() {
    if (check()) {
        cash -= prices[selectedItem];
        state = COOK;
    } else {
        state = WAIT;
    }
}

void Automata::finish() {
    if (state != COOK)
        return;

    state = WAIT;
    cash = 0;
}
