#include "Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    state = OFF;
    selectedIndex = -1;

    menu = {"Tea", "Coffee", "Milk"};
    prices = {50, 100, 70};
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "Machine ON\n";
    }
}

void Automata::off() {
    state = OFF;
    cash = 0;
    std::cout << "Machine OFF\n";
}

void Automata::coin(int amount) {
    if (state == WAIT || state == ACCEPT) {
        cash += amount;
        state = ACCEPT;
        std::cout << "Inserted: " << amount << ", total: " << cash << "\n";
    }
}

void Automata::getMenu() {
    for (int i = 0; i < menu.size(); i++) {
        std::cout << i << ": " << menu[i] << " - " << prices[i] << "\n";
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int index) {
    if (state == ACCEPT && index >= 0 && index < menu.size()) {
        selectedIndex = index;
        state = CHECK;
    }
}

void Automata::check() {
    if (state == CHECK && selectedIndex >= 0) {
        if (cash >= prices[selectedIndex]) {
            state = COOK;
        } else {
            state = WAIT;
        }
    }
}

void Automata::cancel() {
    if (state != OFF) {
        std::cout << "Canceled. Return: " << cash << "\n";
        cash = 0;
        state = WAIT;
    }
}

void Automata::cook() {
    if (state == COOK) {
        std::cout << "Cooking " << menu[selectedIndex] << "...\n";
        cash -= prices[selectedIndex];
    }
}

void Automata::finish() {
    if (state == WAIT) {
        std::cout << "Take your drink\n";
    }
}
