// Copyright 2024 GHA Test Team

#pragma once
#include <string>
#include <vector>

enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    SELECT,
    CHECK,
    COOK,
    DONE
};

class Automata {
 public:
    Automata();

    void on();
    void off();
    void coin(int amount);
    void getMenu() const;
    STATES getState() const;
    void choice(int item);
    void check();
    void cancel();
    void cook();
    void finish();

 private:
    int cash;
    int selected;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
};
