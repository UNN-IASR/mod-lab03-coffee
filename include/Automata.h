// Copyright 2026 MaximLazarenko
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 public:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
    int selectedDrink;

    Automata();
    void on();
    void off();
    void coin(int amount);
    std::vector<std::string> getMenu();
    STATES getState();
    void choice(int item);
    bool check();
    void cancel();
    void cook();
    void finish();
};

#endif  // INCLUDE_AUTOMATA_H_
