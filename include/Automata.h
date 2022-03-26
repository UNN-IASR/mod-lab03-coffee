// Copyright 2022 UNN-IASR
#pragma once
#include <iostream>
#include <string>
#include <array>

using std::cout;
using std::string;
using std::array;

const int MENU_DIMENSION = 7;

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHEAK,
    COOK
};

class Automata {
 private:
    STATES stateOfAutomata;
    double cash;
    array<string, MENU_DIMENSION> menu;
    array<int, MENU_DIMENSION> prices;
    int positionOfCheak;

 public:
    Automata();
    void on();
    void off();
    void coin(double);
    void getMenu();
    STATES getState();
    double getCash();
    void printInfoAboutState();
    void choice(int);
    void check();
    int cancel();
    void cook();
    void finish();
};
