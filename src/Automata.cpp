﻿
// Copyright 2024 Danil Volkov

#include <iostream>
#include <fstream>
#include <string>
#include "../include/Automata.h"

Automata::Automata() {
    cash = 0;
    state = OFF;

    menu = {
    "Americano",
    "Tea (black)",
    "Juice (apple)",
    "Water",
    "Soda (Cola)",
    "Hot chocolate",
    "Cappuccino",
    "Latte"
    };

    prices = { 50, 40, 60, 30, 45, 70, 80, 90 };
}

Automata::~Automata() {}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "The machine is turned on." << endl;
    } else {
        std::cout << "Unavailable transition!" << endl;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "The machine is turned off." << endl;
    } else {
        std::cout << "Unavailable transition!" << endl;
    }
}

void Automata::coin(int amount) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += amount;
        std::cout << "On your account: " << cash << " rub." << endl;
    } else {
        std::cout << "Unavailable transition!" << endl;
    }
}

void Automata::getMenu() {
    if (state == WAIT || state == ACCEPT) {
        for (int i = 0; i < menu.size(); ++i) {
            std::cout << i + 1 << ". " << menu[i]
                << " - " << prices[i] << " rub." << endl;
        }
    } else {
        std::cout << "The function is not available in this state!" << endl;
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int choice) {
    if (state == ACCEPT) {
        if (choice < 1 || choice > menu.size()) {
            std::cout << "Invalid number." << endl;
        } else {
            state = CHECK;
            if (check(choice)) {
                cook(choice);
            }
        }
    } else {
        std::cout << "Unavailable transition!" << endl;
    }
}

bool Automata::check(int choice) {
    if (cash >= prices[choice - 1]) {
        return true;
    }
    std::cout << "Insufficient funds." << endl;
    state = ACCEPT;
    return false;
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        cash = 0;
        state = WAIT;
        std::cout << "The service session has been cancelled." << endl;
    } else {
        std::cout << "Unavailable transition!" << endl;
    }
}

void Automata::cook(int choice) {
    cash -= prices[choice - 1];
    std::cout << "Your " << menu[choice - 1] << " is getting ready." << endl;
    state = COOK;
    finish(choice);
}

void Automata::finish(int choice) {
    std::cout << "Your change: " << cash << endl;
    std::cout << "Your " << menu[choice - 1]
        << " ready. Enjoy your meal!" << endl;
    cash = 0;
    state = WAIT;
}
