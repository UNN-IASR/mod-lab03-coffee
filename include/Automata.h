// Copyright 2022 UNN-IASR

#pragma once
#include <iostream>
#include <string>

using std::string;

enum STATES { COOK, CHECK, ACCEPT, WAIT, OFF };

class Automata {
 public:
  Automata();
  void on();
  void off();
  void coin(const int);
  void getMenu();
  STATES getState();
  void choice(const int);
  void check();
  void cancel();
  void cook();
  void finish();
  
 private:
  int cash;
  string* menu;
  int* prices;
  STATES state;
  int option;
};
