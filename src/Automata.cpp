// Copyright 2022 UNN-IASR
#include "Automata.h"

using std::cout;
using std::endl;

Automata::Automata() {
    cash = 0;
    menu = new std::string[3];
    menu[0] = "Coffee";
    menu[1] = "Tea";
    menu[2] = "Cola";
    prices = new int[3];
    prices[0] = 10;
    prices[1] = 20;
    prices[2] = 30;
    state = OFF;
}
void Automata::on() {
    if (state == OFF) state = WAIT;
}
void Automata::off() {
    if (state == WAIT) state = OFF;
}
void Automata::coin(int money) {
    if (state == WAIT) {
        state = ACCEPT;
    }
    cash += money;
}
void Automata::getMenu() {
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << menu[i] << " " << prices[i] << endl;
    }
}
States Automata::getState() {
    return state;
}
void Automata::choice(int _choice) {
    if (state == ACCEPT) {
        state = CHECK;
        option = _choice;
    }
}
bool Automata::check() {
    if (state == CHECK && cash >= prices[option - 1]) return true;
    return false;
}
int Automata::cancel() {
    int cash2 = 0;
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        cash2 = cash;
        cash = 0;
    }
    return cash2;
}
void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
        cash -= prices[option - 1];
    }
}
int Automata::finish() {
    int temp = 0;
    if (state == COOK) {
        state = WAIT;
        temp = cash;
        cash = 0;
    }
    return temp;
}
