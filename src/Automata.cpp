// Copyright 2022 UNN-IASR
#include "Automata.h"
using std::cout;
using std::endl;
Automata::Automata() {
    state = OFF;
    cash = 0;
    int menuLen = 6;
    bool isEnough = 0;
}
void Automata::on() {
    if (state == OFF)
        state = WAIT;
    else
        cout << "Error" << endl;
}
void Automata::off() {
    if (state == WAIT)
        state = OFF;
    else
        cout << "Error" << endl;
}
void Automata::coin(int money) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += money;
    } else {
        cout << "Error" << endl;
    }
}
void Automata::etMenu() {
    for (int i = 0; i < menuLen; i++) {
        cout << menu[i] << "=" << prices[i] << endl;
    }
}
STATES Automata::getState() {
    return state;
}
void Automata::choice(std::string drink) {
    if (state == ACCEPT) {
        choseDrink = drink;
        state = CHECK;
    } else {
        cout << "Error" << endl;
    }
}
bool Automata::check() {
    if (state == CHECK) {
        for (int i = 0; i < menuLen; i++)
            if (menu[i] == choseDrink) {
                if (prices[i] <= cash) {
                    state = CHECK;
                    cash = cash - prices[i];
                    isEnough = 1;
                }
            }
    } else {
        cout << "Error" << endl;
    }
    return isEnough;
}
void Automata::cancel() {
    state = WAIT;
}
void Automata::cook() {
    if (state == CHECK && isEnough == 1) {
        state = COOK;
        cout << "PSHHHH" << endl;
    } else {
        cout << "Error" << endl;
    }
}
void Automata::finish() {
    if (state == COOK) {
        state = WAIT;
    } else {
        cout << "Error" << endl;
    }
}
