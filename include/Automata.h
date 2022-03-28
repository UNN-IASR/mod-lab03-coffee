// Copyright 2022 UNN-IASR
#pragma once
#include <iostream>
#include <string>
using std::string;
enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
class Automata {
 public:
    int cash = 0;
    int menuLen = 6;
    std::string menu[6] = {
        "cappuchino",
        "latte",
        "americano",
        "tea",
        "chocolate",
        "fried nails" };
    int prices[6] = {
        30, 25, 30, 20, 40, 15
    };
    STATES state = OFF;
    std::string choseDrink;
    bool isEnough = 0;
    Automata();
    void on();
    void off();
    void coin(int money);
    void etMenu();
    STATES getState();
    void choice(std::string drink);
    bool check();
    void cancel();
    void cook();
    void finish();
};
