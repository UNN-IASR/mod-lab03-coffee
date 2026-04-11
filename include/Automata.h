// Copyright 2026 Senatorova Maria

#pragma once
#include <string>
#include <vector>

enum class STATES {
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
  STATES state;
  int selectedIndex;

 public:
  Automata();
  void on();
  void off();
  void coin(double amount);
  void getMenu() const;
  STATES getState() const;
  void choice(int index);
  void check();
  void cook();
  void finish();
  void cancel();
};
