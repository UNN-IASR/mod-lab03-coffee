// Copyright 2022 LepehinM
#include "Automata.h"

using std::string;

Automata::Automata() {
    cash = 0;
    state = Off;
}

void Automata::on() {
    if (state == Off) {
        state = Wait;
    }
}

void Automata::off() {
    if (state == Wait) {
        state = Off;
    }
}

void Automata::coin(int money) {
    if (state == Wait) {
        state = Accept;
    }
    if (state == Accept) {
        cash += money;
    }
}

vector<string> Automata::getMenu() {
    return menu;
}
STATES Automata::getStates() {
    return state;
}

int Automata::choice(string drink) {
    int index = -1;
    for (int i = 0; i < menu.size(); i++) {
        if (drink == menu[i]) {
            if (state == Accept) {
                state = Check;
                index = i;
            }
        }
    }
    return index;
}

bool Automata::check(int index) {
    if (state == Check) {
        if (cash >= prices[index]) {
            return true;
        }
    }
    return false;
}

void Automata::cook(int index) {
    if (state == Check) {
        state = Cook;
        cash -= prices[index];
    }
}

int Automata::cancel() {
    int change = 0;
    if (state == Accept || state == Check) {
        change = cash;
        cash = 0;
        state = Wait;
    }
    return change;
}



int Automata::finish() {
    int change = 0;
    if (state == Cook) {
        state = Wait;
        change = cash;
        cash = 0;
    }
    return change;
}
