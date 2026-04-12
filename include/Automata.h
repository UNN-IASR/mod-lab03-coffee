// Copyright 2022 GHA Test Team
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
 public:
  Automata();

  void on();
  void off();
  void coin(int amount);
  void cancel();
  void choice(int item);
  void check();
  void cook();
  void finish();

  void getMenu() const;
  STATES getState() const;
  int getCash() const;
  int getSelectedItem() const;

 private:
  int cash;
  int selectedItem;
  STATES state;
  std::vector<std::string> menu;
  std::vector<int> prices;
};
