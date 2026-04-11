#include <iostream>
#include "Automata.h"

int main() {
  Automata a;

  a.on();

  a.getMenu();

  a.coin(50);
  a.coin(50);

  a.choice(1);

  a.check();

  a.cook();

  a.finish();

  a.coin(30);
  a.choice(0);
  a.check();

  a.cancel();

  a.off();

  return 0;
}