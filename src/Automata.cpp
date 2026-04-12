// Copyright 2022 UNN-IASR

#include "Automata.h"

#include <iostream>

Automata::Automata() {
    cash = 0;
    state = STATES::OFF;
    selected = -1;

    menu = {"Tea", "Coffee", "Milk"};
    prices = {50, 100, 70};
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
    }
}

void Automata::off() {
    state = STATES::OFF;
    cash = 0;
}

void Automata::coin(int amount) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        cash += amount;
        state = STATES::ACCEPT;
    }
}

void Automata::getMenu() const {
    for (size_t i = 0; i < menu.size(); i++) {
        std::cout << i << ": " << menu[i]
                  << " - " << prices[i] << std::endl;
    }
}

STATES Automata::getState() const {
    return state;
}

void Automata::choice(int index) {
    if (state == STATES::ACCEPT && index >= 0 &&
        index < static_cast<int>(menu.size())) {
        selected = index;
        state = STATES::CHECK;
    }
}

bool Automata::check() {
    if (state == STATES::CHECK) {
        if (cash >= prices[selected]) {
            return true;
        } else {
            state = STATES::WAIT;
            return false;
        }
    }
    return false;
}

void Automata::cancel() {
    cash = 0;
    selected = -1;
    state = STATES::WAIT;
}

void Automata::cook() {
    if (state == STATES::CHECK && cash >= prices[selected]) {
        cash -= prices[selected];
        state = STATES::COOK;
    }
}

void Automata::finish() {
    if (state == STATES::COOK) {
        state = STATES::WAIT;
    }
}
