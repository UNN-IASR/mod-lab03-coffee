// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

enum class STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

struct menuItem {
  std::string itemName;
  double itemPrice;
};

class Automata {
 private:
  double cash = 0;
  double currentCash = 0;
  STATES state = STATES::OFF;
  std::vector<menuItem> menu;
  std::ostream& outStream;

  void cook();
  void finish();
  bool check(size_t itemIndex);

 public:
  Automata(std::ostream& os);
  void on();
  void off();
  void coin(double amount);
  std::vector<menuItem> getMenu();
  STATES getState();
  double choice(size_t itemIndex);
  double cancel();
};

#endif  // INCLUDE_AUTOMATA_H_