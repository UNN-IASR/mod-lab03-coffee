// Copyright 2022 Dacyto

#pragma once
#include <iostream>
#include <string>

using std::string;

enum STATES {
  OFF, WAIT, ACCEPT, CHECK, COOK
  };

class Automata {
 private:
    int cash;
    string menu[8] = {
      "Espresso",
      "Americano",
      "Cappuccino",
      "Latte",
      "Flat White",
      "Triple Flat White",
      "Black Tea",
      "Hot Chocolate"
      };
    int prices[8] = {
    35, 40, 60, 75, 55, 65, 30, 50
    };
    int variety;
    STATES state;

 public:
    Automata();
    void on();
    void off();
    void coin(int c);
    STATES getState();
    void getMenu();
    void choice(int x);
    int cancel();
    bool check();
    void cook();
    int finish();
};
