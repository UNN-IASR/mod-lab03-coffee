// Copyright 2022 GHA Test Team

#include "Automata.h"
#include <iostream>

int main() {
  Automata a;
  std::cout << a.getState() << std::endl;
  a.on();
  std::cout << a.getState() << std::endl;
  a.getMenu();
  a.coin(50);
  std::cout << a.getState() << std::endl;
  a.coin(10);
  a.choice(2);
  std::cout << a.getNumberSelectedDrink() << std::endl;
  if (a.check()) {
    std::cout << a.getState() << std::endl;
    a.cook();
  } else {
    a.cancel();
  }
  std::cout << a.getState() << std::endl;
  a.coin(15);
  a.choice(1);
  std::cout << a.getCash() << std::endl;
  if (a.check())
    a.cook();
  else
    a.cancel();
  std::cout << a.getState() << std::endl;
  a.cook();
  a.off();
}
