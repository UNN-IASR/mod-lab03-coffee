// Copyright 2026 GHA Test Team

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
 public:
    double cash;
    std::vector<std::string> menu;
    std::vector<double> prices;
    STATES state;

    Automata();

    void on();
    void off();
    void coin(double amount);
    void etMenu();
    STATES getState();
    bool choice(int item);
    bool check(int item);
    void cancel();
    void cook(int item);
    void finish();
};

#endif  // INCLUDE_AUTOMATA_H_
