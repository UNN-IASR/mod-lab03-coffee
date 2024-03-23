// Copyright 2024 alenkaLo
#include "Automata.h"
#include <string>
#include <iostream>

Automata::Automata() {
    state = state_off;
    cash = 0;
}
Automata::Automata(states st) {
    state = st;
    cash = 0;
}
void Automata::on() {
    if (state == state_off)
        state = state_wait;
    else
        state = state;
}
void Automata::off() {
    if (state == state_wait)
        state = state_off;
    else
        state = state;
}
void Automata::coin(int sum) {
    if (state == state_wait)
        state = state_accept;
    if (state == state_accept) {
        cash += sum;
        std::cout << "Taken summa: " << sum << std::endl;
    }
    else
        state = state;
}
void Automata::setMenu() {
    if (state != state_off) {
        std::cout << "MENU:" << std::endl;
        for (int i = 0; i < menu.size(); i++) {
            std::cout <<  menu[i] << ": " << prices[i] << std::endl;
        }
    }
}
states Automata::getState() {
    return state;
}
void Automata::finish() {
    if (state == state_finish) {
        state = state_wait;
        std::cout << "thank for order)" << std::endl;
    }
    else
        state = state;
}
void Automata::cook() {
    if (state == state_cook) {
        state = state_finish;
        cash -= prices[n];
        std::cout << "Process cooking..." << std::endl;
        finish();
    }
}
void Automata::check() {
    if (state == state_check) {
        if (cash >= prices[n]) {
            state = state_cook;
            cook();
        }
        else
            std::cout << "Not amout money";
    }
    else
        state = state;
}
void Automata::choice(int num) {
    if (state == state_accept) {
        n = num;
        state = state_check;
        check();
    }
    else
        state = state;
}
void Automata::cancel() {
    if (state == state_accept || state == state_check)
        state = state_wait;
    else
        state = state;
}
