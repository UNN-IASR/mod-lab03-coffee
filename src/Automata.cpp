// Copyright 2022 UNN-IASR
#include "Automata.h"
using std::cout;
using std::endl;

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
    }
}

void Automata::coin(int m) {
    if (state == WAIT) state = ACCEPT;
    cash = cash + m;
}

string* Automata::etMenu() {
    return menu;
}

void Automata::choice(int ch) {
    if (state == ACCEPT) {
        this->choice_p = ch;
        state = CHECK;
        check();
    }
}

void Automata::check() {
    if (state == CHECK) {
        if (cash - prices[choice_p] >= 0) {
            cook();
        } else {
            state = ACCEPT;
        }
    }
}

int Automata::cancel() {
    if (state == ACCEPT || state == CHECK || state == WAIT) {
        state = WAIT;
        int r = cash;
        cash = 0;
        return r;
    } else {
        return 0;
    }
}

void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
    }
}

void Automata::finish(int f) {
    state = WAIT;
    cash = cash - prices[f - 1];
    choice_p = -1;
}
