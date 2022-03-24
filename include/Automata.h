// Copyright 2022 UNN-IASR
#pragma once
#include <iostream>
#include <array>
#include <string>
#include <stdexcept>

class Automata {
 public:
    Automata();

 public:
    void on();
    void off();
    void coin(const int);
    void check();
    void choice(const int);
    void cook();
    void finish();
    void cancel();

    void getMenu();
    int getState();

 private:
    enum STATES {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };

 private:
    size_t myChoice;
    double myCash;
    std::array<std::string, 10> myMenu;
    std::array<int, 10> myPrices;
    STATES myState;
};
