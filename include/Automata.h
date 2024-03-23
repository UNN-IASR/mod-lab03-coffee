
// Copyright 2024 StatsenkoArs

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 private:
    int cash;
    std::vector <std::string> menu;
    std::vector <int> prices;
    STATES state;
 public:
    Automata();
    void on();
    void off();
    int coin();
    std::vector <std::string> getMenu();
    STATES getState();
    void choice(std::string choice);
    void cancel();
 private:
    void cook();
    void finish();
};

#endif  // INCLUDE_AUTOMATA_H_
