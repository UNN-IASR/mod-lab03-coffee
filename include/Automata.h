// Copyright 2026 Yurtaev Nikita

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

class Automata {
 public:
  enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
  };

  Automata();
  ~Automata();

  void on();
  void off();
  void coin(double amount);
  void getMenu();
  STATES getState();
  void choice(int index);
  void check();
  void cancel();
  void cook();
  void finish();

 private:
  double cash;
  std::vector<std::string> menu;
  std::vector<double> prices;
  STATES state;
  int choiceIndex;
};

#endif  // INCLUDE_AUTOMATA_H_
