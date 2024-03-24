// Copyright 2024 Anna Chernyadeva

#include <iostream>
#include "Automata.h"

Automata::Automata() {
    cash = 0;
    state = OFF;
    menu = { "Water",
        "Earl Gray Tea",
        "Americano",
        "Cappuchino",
        "Latte",
        "Matcha"};

    prices = { 10, 15, 30, 40, 45, 50 };
}

Automata::~Automata() {
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "On" << std::endl;
    } else {
        std::cout << "Wrong transition!" << std::endl;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "Off" << std::endl;
    } else {
        std::cout << "Wrong transition!" << std::endl;
    }
}

void Automata::coin(int money) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += money;
        std::cout << "Money:" << cash << std::endl;
    } else {
        std::cout << "Wrong transition!" << std::endl;
    }
}

void Automata::getMenu() {
    if (state == WAIT || state == ACCEPT) {
        for (int i = 0; i < menu.size(); ++i) {
            std::cout << i + 1 << ") " << menu[i]
                << " - " << prices[i] << ";" << std::endl;
        }
    } else {
        std::cout << "Wrong transition!" << std::endl;
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int selection) {
    if (state == ACCEPT) {
        if (selection < 1 || selection > menu.size()) {
            std::cout << "Invalid number" << std::endl;
        } else {
            state = CHECK;
            if (check(selection)) {
                cook(selection);
            }
        }
    } else {
        std::cout << "Wrong transition!" << std::endl;
    }
}

bool Automata::check(int selection) {
    if (cash >= prices[selection - 1]) {
        return true;
    }
    std::cout << "Not enough money" << std::endl;
    state = ACCEPT;
    return false;
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        cash = 0;
        std::cout << "Cancel" << std::endl;
    } else {
        std::cout << "Wrong transition!" << std::endl;
    }
}

void Automata::cook(int selection) {
    if (state == CHECK) {
        state = COOK;
        cash -= prices[selection - 1];
        std::cout << "Your drink in progress"
            << std::endl;
        finish(selection);
    } else {
        std::cout << "Wrong transition!" << std::endl;
    }
}

void Automata::finish(int selection) {
    if (state == COOK) {
        std::cout << "Change: " << cash << std::endl;
        std::cout << "Take your drink" << std::endl;
        cash = 0;
        state = WAIT;
    } else {
        std::cout << "Wrong transition!" << std::endl;
    }
}
