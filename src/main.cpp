// Copyright 2022 UNN-IASR

#include "Automata.h"
#include <iostream>

int main() {
  Automata* automata = new Automata(std::cout);
  automata->on();
  automata->getMenu();
  automata->coin(50);
  automata->choice(1);
  automata->off();
  return 0;
}
