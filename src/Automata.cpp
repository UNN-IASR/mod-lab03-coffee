// Copyright 2022 UNN-IASR
#include "Automata.h"
using std::cout;
using std::endl;

void Automata::Off() {
    if (state == WAIT) {
        state = OFF;
    }
}
void Automata::On() {
    if (state == OFF) {
        state = WAIT;
    }
}
void Automata::AddCoin(int cash) {
    if (state == WAIT) state = ACCEPT;
    amount += cash;
}
void Automata::ChoiceMenu(int position) {
    if (state == ACCEPT) {
        selectedMenu = position;
        state = CHECK;
        Check();
    }
}
string* Automata::ReturnChoisenMenu() {
    return menu;
}
void Automata::Check() {
    if (state == CHECK) {
        if (amount - prices[selectedMenu] >= 0) {
            Cook();
        } else {
            state = ACCEPT;
        }
    }
}
void Automata::Cook() {
    if (state == CHECK) {
        state = COOK;
    }
}
int Automata::Cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        double oddmoney = amount;
        amount = 0;
        return oddmoney;
    } else {
        return 0;
    }
}
void Automata::Finish(int f) {
    if (state == COOK) {
        state = WAIT;
        amount -= prices[f - 1];
        selectedMenu = -1;
    }
}
