// Copyright 2022 UNN-IASR
#pragma once
#include <iostream>
#include <string>

using std::string;

enum States {
  OFF,
  WAIT,
  ACCEPT,
  CHECK,
  COOK
};

class Automata {
 private:
    int cash;
    string* menu;
    int* prices;
    States state;
    int option;

 public:
    Automata();
    void on();
    void off();
    void coin(int money);
    void getMenu();
    States getState();
    void choice(int _choice);
    int cancel();
    bool check();
    void cook();
    int finish();
};
