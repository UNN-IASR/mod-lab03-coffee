// Copyright 2022 UNN-IASR
#pragma once
#include <string>

using std::string;

enum States {Off, Wait, Accept, Check, Cook};

class Automata {
 private:
  States state;
  int cash;
  string menu[3] = {"Espresso", "Latte", "Cacao"};
  int price[3] = {80, 110, 70};
 public:
  Automata();
  void on();
  void off();
  void coin(int value);
  void getMenu();
  States getState();
  int choice(string value);
  bool check(int index);
  void cancel();
  void cook(int index);
  void finish();
};
