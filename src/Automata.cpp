// Copyright 2024 Ekaterina Ryzhevskaya

#include <iostream>
#include <windows.h>
#include "../include/Automata.h"

Automata::Automata() {
    state = OFF;
    cash = 0;

    menu = { "Tea", "Americano", "Cappucino", "Latte", "Cocoa", "Water" };
    prices = { 80, 100, 150, 150, 130, 50 };
}

int Automata::getCash() {
    return cash;
}

void Automata::on() {
    if (state == OFF) state = WAIT;
}

void Automata::off() {
    if (state == WAIT) state = OFF;
}

void Automata::coin(int sum) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += sum;
    }
}

void Automata::getMenu() {
    if (state == WAIT || state == ACCEPT) {
        std::cout << "MENU:" << std::endl;
        for (int i = 0; i < menu.size(); i++) {
            std::cout << i + 1 << ". " << menu[i] << " - " << prices[i] << std::endl;
        }
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int num) {
    if (state == ACCEPT && num >= 1 && num <= menu.size()) {
        state = CHECK;
        check(num);
    }
}

void Automata::check(int num) {
    if (cash >= prices[num - 1]) {
        cash -= prices[num - 1];
        cook();
    } else {
        state = ACCEPT;
    }
}

void Automata::cancel() {
    if (state == ACCEPT) {
        cash = 0;
        state = WAIT;
    }
}

void Automata::cook() {
    state = COOK;
    Sleep(1000);
    finish();
}

void Automata::finish() { // отдал сдачу
    cash = 0;
    state = WAIT;
}
