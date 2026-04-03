// Copyright 2026 MaximLazarenko
#include "Automata.h"
#include <string>
#include <vector>

Automata::Automata() {
    cash = 0;
    state = OFF;
    selectedDrink = -1;
    menu = {"Кофе", "Чай", "Молоко", "Капучино"};
    prices = {50, 30, 20, 70};
}

void Automata::on() {
    if (state == OFF)
        state = WAIT;
}

void Automata::off() {
    if (state == WAIT)
        state = OFF;
}

void Automata::coin(int amount) {
    if (state == WAIT || state == ACCEPT) {
        cash += amount;
        state = ACCEPT;
    }
}

std::vector<std::string> Automata::getMenu() {
    return menu;
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int item) {
    if (state == ACCEPT) {
        selectedDrink = item;
        state = CHECK;
    }
}

bool Automata::check() {
    if (state == CHECK) {
        if (cash >= prices[selectedDrink])
            return true;
    }
    return false;
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        cash = 0;
        selectedDrink = -1;
        state = WAIT;
    }
}

void Automata::cook() {
    if (state == CHECK && check())
        state = COOK;
}

void Automata::finish() {
    if (state == COOK) {
        cash -= prices[selectedDrink];
        selectedDrink = -1;
        state = WAIT;
    }
}
