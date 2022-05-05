// Copyright 2022 UNN-IASR
#pragma once
#include <iostream>
#include <string>

using std::string;

enum STATES {
    OFF, WAIT, ACCEPT, CHECK, COOK
};

class Automata {
 private:
    int Cash;
    string* Menu;
    int* Prices;
    STATES State;
    int order;

 public:
    Automata();
    void on();
    void off();
    void coin(int);
    void getMenu();
    STATES getState();
    void choice(int);
    bool check();
    int cancel();
    void cook();
    int finish();
};
