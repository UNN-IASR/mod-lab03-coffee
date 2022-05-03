// Copyright 2020 GHA Test Team
#include <fstream>
#include <iostream>
#include "Automata.h"
using std::cout;
using std::endl;

Automata::Automata() {
}

void Automata::on() {
    this->state = STATES::WAIT;
}

void Automata::off() {
    this->state = STATES::OFF;
}

void Automata::coin(int coins) {
    this->cash += coins;
    this->state = STATES::ACCEPT;
}

string Automata::getMenu() {
    string str = "";
    for (size_t i = 0; i < size(this->menu); ++i)
        str += this->menu[i] + ": " + std::to_string(this->prices[i]) + "\n";
    return str;
}

STATES Automata::getState() {
    return this->state;
}

void Automata::choice() {
    this->state = STATES::CHECK;
}

bool Automata::check(string name) {
    int ind = -1;
    for (int i = 0; i < this->menu.size(); ++i)
        if (this->menu[i] == name)
            ind = i;
    if (ind != -1 && this->cash >= this->prices[ind]) {
        this->cash -= this->prices[ind];
        return true;
    }
    return false;
}

void Automata::cancel() {
    this->state = STATES::WAIT;
}

void Automata::cook() {
    this->state = STATES::COOK;
}

void Automata::finish() {
    this->state = STATES::WAIT;
}

int Automata::getRest() {
    return this->cash;
}

void Automata::printState(STATES s) {
    switch (s) {
    case STATES::WAIT:
        cout << "The automate is waiting for an order..." << endl;
        break;
    case STATES::ACCEPT:
        cout << "Acceptance of money..." << endl;
        break;
    case STATES::CHECK:
        cout << "Cash check..." << endl;
        break;
    case STATES::COOK:
        cout << "Preparing a drink..." << endl;
        break;
    case STATES::OFF:
        cout << "The automate is turned off." << endl;
        break;
    default:
        break;
    }
}

int Automata::work(string name, int coins, bool output) {
    if (output)
        printState(this->getState());
    on();
    if (output)
        printState(this->getState());
    coin(coins);
    if (output)
        printState(this->getState());
    choice();
    if (output)
        printState(this->getState());
    if (!check(name)) {
        finish();
        if (output)
            printState(this->getState());
        return getRest();
    } else {
        cook();
        if (output)
            printState(this->getState());
    }
    finish();
    if (output)
        printState(this->getState());
    off();
    if (output)
        printState(this->getState());
    return getRest();
}

