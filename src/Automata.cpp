// Copyright 2022 UNN-IASR
#include "Automata.h"

using std::cout;
using std::endl;

Automata::Automata() {
    Menu = new std::string[4];
    Menu[0] = "Lemonade";
    Menu[1] = "Hot Chocolate";
    Menu[2] = "Coffee";
    Menu[3] = "Water";
    Prices = new int[4];
    Prices[0] = 100;
    Prices[1] = 200;
    Prices[2] = 300;
    Prices[3] = 400;
    Cash = 0;
    State = OFF;
}
void Automata::on() {
    if (this->State == OFF) {
this->State = WAIT;
    }
}
void Automata::off() {
    if (this->State == WAIT) {
this->State = OFF;
    }
}
void Automata::coin(int m) {
    if (this->State == WAIT) {
this->State = ACCEPT;
    }
    Cash += m;
}
void Automata::getMenu() {
    for (int i = 0; i < 4; i++) {
cout << i + 1 << ": " << Menu[i] << " " << Prices[i];
cout << '\n';
    }
}
STATES Automata::getState() {
    return State;
}
void Automata::choice(int order) {
    if (this->State == ACCEPT) {
this->State = CHECK;
this->order = order;
    }
}
bool Automata::check() {
    if (this->State == CHECK && Cash >= Prices[order - 1])
return true;
  return false;
}
int Automata::cancel() {
    int cash2 = 0;
    if (this->State == ACCEPT || this->State == CHECK) {
this->State = WAIT;
cash2 = Cash;
Cash = 0;
    }
    return cash2;
}
void Automata::cook() {
    if (this->State == CHECK) {
this->State = COOK;
Cash -= Prices[order - 1];
    }
}
int Automata::finish() {
    int sym = 0;
    if (this->State == COOK) {
this->State = WAIT;
sym = Cash;
Cash = 0;
    }
    return sym;
}
