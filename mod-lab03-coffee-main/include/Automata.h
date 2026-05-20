// Copyright 2026 upi52
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <cstddef>
#include <string>
#include <utility>
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
  Automata(const std::vector<std::string>& drinks,
           const std::vector<int>& drink_prices);

  bool on();
  bool off();
  bool coin(int value);

  std::vector<std::pair<std::string, int>> getMenu() const;
  std::string etMenu() const;
  STATES getState() const;
  int getCash() const;
  int getLastRefund() const;
  int getSelectedPrice() const;
  std::string getLastDrink() const;

  bool choice(std::size_t drink_index);
  bool check() const;
  int cancel();
  bool cook();
  int finish();

 private:
  static void validateMenu(const std::vector<std::string>& drinks,
                           const std::vector<int>& drink_prices);

  int cash_;
  std::vector<std::string> menu_;
  std::vector<int> prices_;
  STATES state_;
  int selected_index_;
  int last_refund_;
  std::string last_drink_;
};

std::string toString(STATES state);

#endif
