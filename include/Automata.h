// Copyright 2024 alenkaLo
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <iostream>
#include <string>
#include <vector>

enum states {
    state_off, state_cook, state_wait,
    state_accept, state_check, state_finish
};

class Automata {
 private:
    int cash;
    std::vector <std::string> menu = { "1. latte", "2. americano", "3. tea" };
    std::vector <int> prices = { 150, 130, 50 };
    states state;
    int n;
 public:
    Automata();
    explicit Automata(states);
    void on();
    void off();
    void coin(int);
    void setMenu();
    states getState();
    void choice(int);
    void check();
    void cancel();
    void cook();
    void finish();
};
#endif  // INCLUDE_AUTOMATA_H_
