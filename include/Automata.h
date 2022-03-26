// Copyright 2022 UNN-IASR
#pragma once
#include <iostream>
#include <string>
enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
using std::string;
class Automata {
 public:
    STATES state;
    int money;
    const string menu[9] = {
        "Ristretto",
        "Espresso",
        "Lungo",
        "Americano",
        "Caffe Crema",
        "Doppio",
        "Romano",
        "Cuba",
        "Zorro",
    };
    int choiseCustomer;
    const int prices[9] = {
        10, 20, 30, 40, 50, 60, 70, 80, 90,
    };

 public:
    Automata();
    void on();
    void off();
    void coin(int x);
    void getMenu();
    void getState();
    void choice(int x);
    bool check();
    int whereIsMyMoney();
    void cancel();
    void cook();
    void finish();
    void error();
};
