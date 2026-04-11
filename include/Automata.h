#ifndef AUTOMATA_H
#define AUTOMATA_H

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
  double cash;                       // текущие деньги
  std::vector<std::string> menu;     // напитки
  std::vector<double> prices;        // цены
  STATES state;                      // текущее состояние
  int choiceIndex;                   // выбранный напиток
};

#endif  // AUTOMATA_H