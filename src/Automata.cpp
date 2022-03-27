// Copyright 2022 UNN-IASR
#include "Automata.h"

using std::cout;
using std::endl;

Automata::Automata() {
    state = OFF;
    cash = 0;
}

states Automata::getState() {
    return state;
}

void Automata::getMenu() {
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << menu[i] << " " << prices[i] << " rub" << endl;
    }
}

void Automata::on() {
    if (state == OFF) state = WAIT;
}

void Automata::off() {
    if (state == WAIT) state = OFF;
}

void Automata::coin(int c) {
    if (state == WAIT) {
        state = ACCEPT;
    }
    cash += c;
}

int Automata::cancel() {
    int money = 0;

    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        money = cash;
        cash = 0;
    }

    return money;
}

void Automata::choice(int k) {
    if (state == ACCEPT) {
        state = CHECK;
        selection = k;
    }
}

bool Automata::check() {
    if (state == CHECK && cash >= prices[selection - 1]) return true;
    return false;
}

void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
        cash -= prices[selection - 1];
    }
}

int Automata::finish() {
    int change = 0;

    if (state == COOK) {
        state = WAIT;
        change = cash;
        cash = 0;
    }

    return change;
}
