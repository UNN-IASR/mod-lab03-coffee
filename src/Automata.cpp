// Copyright 2026 Senatorova Maria

#include <iostream>
#include "Automata.h"

Automata::Automata() {
    cash = 0;
    state = STATES::OFF;
    selectedIndex = -1;

    menu = {"Latte", "Capuchino", "Americano"};
    prices = {80, 85, 50};
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        std::cout << "Automata ON\n";
    }
}

void Automata::off() {
    state = STATES::OFF;
    cash = 0;
    std::cout << "Automata OFF\n";
}

void Automata::coin(double amount) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        cash += amount;
        state = STATES::ACCEPT;
        std::cout << "Inserted: " << amount << ", Total: " << cash << "\n";
    }
}

void Automata::getMenu() const {
    std::cout << "Menu:\n";
    for (size_t i = 0; i < menu.size(); i++) {
        std::cout << i << ": " << menu[i] << " - " << prices[i] << "\n";
    }
}

STATES Automata::getState() const {
    return state;
}

void Automata::choice(int index) {
    if (state == STATES::ACCEPT && index >= 0 && index < menu.size()) {
        selectedIndex = index;
        state = STATES::CHECK;
        std::cout << "Selected: " << menu[index] << "\n";
    }
}

void Automata::check() {
    if (state == STATES::CHECK) {
        if (cash >= prices[selectedIndex]) {
            state = STATES::COOK;
            std::cout << "Enough money\n";
        } else {
            std::cout << "Not enough money\n";
            state = STATES::WAIT;
        }
    }
}

void Automata::cook() {
    if (state == STATES::COOK) {
        std::cout << "Cooking " << menu[selectedIndex] << "...\n";
        cash -= prices[selectedIndex];
        finish();
    }
}

void Automata::finish() {
    std::cout << "Take your drink\n";
    std::cout << "Change: " << cash << "\n";
    cash = 0;
    state = STATES::WAIT;
}

void Automata::cancel() {
    std::cout << "Canceled. Return: " << cash << "\n";
    cash = 0;
    state = STATES::WAIT;
}
