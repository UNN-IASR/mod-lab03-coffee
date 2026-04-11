// Copyright 2022 GHA Test Team

#pragma once

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

enum STATES {
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
  int indexSelectedDrink;
 public:
  Automata();
  void on();
  void off();
  void coin(unsigned int money);
  void getMenu();
  std::string getState();
  void choice(unsigned int numberDrink);
  bool check();
  void cancel();
  void cook();
  void finish();
  int getCash() const;
  unsigned int getNumberSelectedDrink() const;
};

#endif
