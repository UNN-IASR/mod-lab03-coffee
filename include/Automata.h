// Copyright 2022 UNN-IASR
#pragma once
#include <stdio.h>
#include <iostream>
#include <string>

class Automata {
 private:
  int cash;
  int selection;
  std::string menu[4];
  int prices[4];
  bool isChecked;

 public:
  enum States {
    OFF, WAIT, ACCEPT, CHECK, COOK, FINISH
  };
  States state;
  Automata();
  void on();
  void off();
  void coin(int);
  void getMenu();
  States getState();
  void choice(int);
  void check();
  void cancel();
  void cook();
  void finish();
};
