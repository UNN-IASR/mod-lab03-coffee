// Copyright 2022 UNN-IASR
#include "Automata.h"
using std::cout;
using std::endl;

void Automata::On() {
    if (state == OFF) {
        state = WAIT;
    }
}

void Automata::Off() {
    if (state == WAIT) {
        state = OFF;
    }
}

void Automata::AddCoin(int _money) {
    if (state == WAIT) state = ACCEPT;
    _amount += _money;
}

string* Automata::ReturnChoisenMenu() {
    return menu;
}

void Automata::ChoiceMenu(int _position) {
    if (state == ACCEPT) {
        _selectedMenu = _position;
        state = CHECK;
        Check();
    }
}

void Automata::Check() {
    if (state == CHECK) {
        if (_amount - prices[_selectedMenu] >= 0) {
            Cook();
        } else {
            state = ACCEPT;
        }
    }
}

int Automata::Cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        double oddmoney = _amount;
        _amount = 0;
        return oddmoney;
    } else {
        return 0;
    }
}

void Automata::Cook() {
    if (state == CHECK) {
        state = COOK;
    }
}

void Automata::Finish(int f) {
    if (state == COOK) {
        state = WAIT;
        _amount -= prices[f - 1];
        _selectedMenu = -1;
    }
}
