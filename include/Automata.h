// Copyright 2020 GHA Test Team
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <string>
#include <vector>
using std::string;
using std::vector;

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
 private:
    int cash = 0;
    vector<string> menu{ "Latte", "Cappuccino", "Espresso" };
    vector<int> prices{ 10, 12, 15 };
    STATES state = STATES::OFF;

 public:
    Automata();
    void on();
    void off();
    void coin(int coins);
    string getMenu();
    STATES getState();
    void choice();
    bool check(string name);
    void cancel();
    void cook();
    void finish();

    int getRest();
    void printState(STATES s);
    int work(string name, int coins, bool output = false);
};

#endif  // INCLUDE_AUTOMATA_H_

