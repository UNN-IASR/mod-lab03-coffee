// Copyright 2022 UNN-IASR

#pragma once
#include <iostream>
#include <string>

using std::string;

enum states {
    OFF, WAIT, ACCEPT, CHECK, COOK
};

class Automata {
 private:
    int cash;
    string menu[5] = {
        "Coffee",
        "Coffee with milk",
        "Black tea",
        "Coca Cola",
        "Mirinda"
    };
    int prices[5] = {
        120, 150, 80, 150, 120
    };
    states state;
    int selection;

 public:
    Automata();
    void on();
    void off();
    void coin(int c);
    void getMenu();
    states getState();
    void choice(int k);
    bool check();
    int cancel();
    void cook();
    int finish();
};
