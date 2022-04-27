// Copyright 2022 UNN-IASR
#pragma once

#include <stdio.h>
#include <iostream>
#include <string>

#define MENU_ITEMS_COUNT 5

class Automata {
 private:
    int cash;
    int selectedItem;
    std::string menu[MENU_ITEMS_COUNT];
    int prices[MENU_ITEMS_COUNT];
    void initMenu();

 public:
    enum States {
        OFF, WAIT, ACCEPT, CHECK, COOK, FINISH
    };

    States state;

    Automata();

    void on();

    void off();

    void coin(int);

    void getMenu();

    States getState();

    void choice(int);

    bool check();

    void cancel();

    void cook();

    void finish();
};
