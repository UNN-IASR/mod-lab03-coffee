// Copyright 2022 UNN-IASR
#include <iostream>
#include <string>
#include <stdexcept>
#include "Automata.h"

using std::cout;
using std::endl;
using std::invalid_argument;
using std::logic_error;

Automata::Automata() {
    cash = 0;
    state = Off;
}

void Automata::on() {
    if (state == Off) {
        state = Wait;
    } else {
        throw logic_error("Error, invalid operation");
    }
}

void Automata::off() {
    if (state == Wait) {
        state = Off;
    } else {
        throw logic_error("Error, invalid operation");
    }
}

void Automata::coin(int value) {
    if (state == Wait) {
        state = Accept;
        cash += value;
    } else {
        throw logic_error("Error, invalid operation");
    }
}

void Automata::getMenu() {
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ": " << menu[i] << " - " << price[i] << endl;
    }
}

States Automata::getState() {
    return state;
}

int Automata::choice(string drink) {
    int index = -1;
    for (int i = 0; i < 3; i++) {
        if (drink == menu[i]) {
            if (state == Accept) {
                state = Check;
                index = i;
            } else {
                throw logic_error("Error, invalid operation");
            }
        }
    }
    return index;
}

bool Automata::check(int index) {
    if (state == Check) {
        if (cash >= price[index]) {
            return true;
        } else {
            return false;
        }
    } else {
        throw logic_error("Error, invalid operation");
    }
}

void Automata::cancel() {
    if (state == Accept || state == Check) {
        state = Wait;
        cout << "You have" << cash << "money" << endl;
        getState();
    } else {
        throw logic_error("Error! Incorrect operation.");
    }
}

void Automata::cook(int index) {
    if (state == Check) {
        state = Cook;
        cash -= price[index];
    } else {
        throw logic_error("Error! Incorrect operation.");
    }
}

void Automata::finish() {
    if (state == Cook) {
        state = Wait;
        cout << "You have" << cash << "money" << endl;
        getState();
    } else {
        throw logic_error("Error! Incorrect operation.");
    }
}
