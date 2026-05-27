// Copyright 2026 Belev Timur
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <string>
#include <vector>

enum State {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
 private:
    double cash;
    std::vector<std::string> menu;
    std::vector<double> prices;
    State state;
    std::string selectedDrink;
    double selectedPrice;

 public:
    Automata();
    void on();
    void off();
    void coin(double amount);
    std::string getMenu();
    State getState();
    bool choice(int index);
    bool check();
    void cancel();
    void cook();
    void finish();
    double getCash();
    void loadMenu();
    void giveChange();
};
#endif  // INCLUDE_AUTOMATA_H_
