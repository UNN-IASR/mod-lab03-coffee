// Copyright 2026
#include "Automata.h"
#include <string>
#include <sstream>

Automata::Automata() : cash(0.0), state(STATES::OFF) {
    menu = {"Tea", "Coffee", "Milk", "Hot Chocolate"};
    prices = {50.0, 80.0, 60.0, 100.0};
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::ON;
    }
}

void Automata::off() {
    if (state == STATES::OFF) {
        return;
    }
    if (cash > 0) {
        cash = 0.0;
    }
    state = STATES::OFF;
}

void Automata::coin(double amount) {
    if (state == STATES::ON || state == STATES::ACCEPT) {
        if (amount > 0) {
            cash += amount;
            state = STATES::ACCEPT;
        }
    }
}

std::string Automata::getMenu() {
    std::stringstream ss;
    for (size_t i = 0; i < menu.size(); ++i) {
        ss << i + 1 << ". " << menu[i] << " - " << prices[i] << " rub\n";
    }
    return ss.str();
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int drinkNumber) {
    if (state == STATES::ACCEPT) {
        if (drinkNumber >= 1 && drinkNumber <= static_cast<int>(menu.size())) {
            if (check(drinkNumber - 1)) {
                state = STATES::COOK;
            } else {
                state = STATES::WAIT; 
            }
        }
    }
}

bool Automata::check(int index) {
    if (state == STATES::ACCEPT || state == STATES::WAIT) {
        if (cash >= prices[index]) {
            state = STATES::CHECK;
            return true;
        }
    }
    return false;
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::WAIT) {
        if (cash > 0) {
            cash = 0.0;
        }
        state = STATES::ON;
    }
}

void Automata::cook() {
    if (state == STATES::COOK) {
        state = STATES::FINISH;
    }
}

void Automata::finish() {
    if (state == STATES::FINISH) {
        cash = 0.0;
        state = STATES::ON;
    }
}

double Automata::getCash() const {
    return cash;
}