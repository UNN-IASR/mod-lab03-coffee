// Copyright 2022 UNN-IASR

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
 private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
    int selected;

 public:
    Automata();

    void on();
    void off();
    void coin(int amount);
    void getMenu() const;
    STATES getState() const;
    void choice(int index);
    bool check();
    void cancel();
    void cook();
    void finish();
};

#endif  
