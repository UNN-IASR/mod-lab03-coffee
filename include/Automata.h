// Copyright 2022 Yuriy Korshunov

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <map>
#include <string>
#include <stdexcept>
#include <iostream>

class Automata {
 private:
    enum States {
        OFF,
        WAIT,
        ACCEPT,
        COOK,
        CHECK
    };
    struct menuItem {
        std::string name;
        int price;
    };
    std::map<int, menuItem> menu;
    States state;
    int cash;
    menuItem item;

 public:
    Automata();

    void on();
    void off();
    void coin(const int value);
    void choice(const int value);
    bool check();
    void cancel();
    void cook();
    void finish();

    void getMenu();
    int getState();
    int getCash();
    menuItem getChoice();
};

#endif // INCLUDE_AUTOMATA_H_
