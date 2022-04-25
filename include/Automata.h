// Copyright 2022 LepehinM
#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;
enum STATES {
    Off,
    Wait,
    Accept,
    Check,
    Cook,
};

class Automata {
 private:
    int cash;
    STATES state;
    const vector<string> menu = { "coffee", "tea", "cocoa"};
    const vector<int> prices = {100, 70, 80 };
 public:
    Automata();
    void on();
    void off();
    void coin(int money);
    vector<string> getMenu();
    STATES getStates();
    int choice(string drink);
    bool check(int index);
    int cancel();
    void cook(int index);
    int finish();
};
