// Copyright 2024 Kokorin Alexandr

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <vector>
#include <string>

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;

 public:
    Automata();
    ~Automata();

    void on();
    void off();
    void coin(int);
    void getMenu();
    STATES getState();
    void choice(int);
    void check(int);
    void cook(int);
    void finish();
    void cancel();
};

#endif  // INCLUDE_AUTOMATA_H_
