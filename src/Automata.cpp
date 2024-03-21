
// Copyright 2024 StatsenkoArs

#include "Automata.h"

Automata::Automata() {
    cash = 0;
    menu = {"Coffee", "Tea", "Cocoa", "Water"};
    prices = {3, 2, 2, 1};
    state = OFF;
}

void Automata::on() {
    if (state == OFF) state = WAIT;
}


void Automata::off() {
    if (state == WAIT) state = OFF;
}

int Automata::coin() {
    if (state = WAIT) state = ACCEPT;
    cash++;
    return cash;
}

void Automata::choice(std::string choice) {
    if (state == ACCEPT) state = CHECK;
    for (std::string s : menu) {
        if (s == choice) {
            int ind = std::distance(menu.begin(),
                std::find(menu.begin(), menu.end(), s));
            if (cash >= prices[ind]) {
                cash -= prices[ind];
                cook();
            }
        }
    }
}

void Automata::cancel() {
    if (state == CHECK) state = WAIT;
}

void Automata::cook() {
    state = COOK;

    // abracadabra

    finish();
}

void Automata::finish() {
    state = WAIT;
}

std::vector<std::string> Automata::getMenu() {
    std::vector <std::string> mp;
    for (int i = 0; i < menu.size(); i++) {
        mp.push_back(menu[i] + " - "
            + std::to_string(prices[i]));
    }
    return mp;
}

STATES Automata::getState() {
    return state;
}
