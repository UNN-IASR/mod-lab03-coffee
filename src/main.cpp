// Copyright 2022 Dacyto

#include <iostream>
#include "Automata.h"

using std::string;
using std::cout;
using std::endl;

int main() {
  Automata Vend; // Vending Machine

  Vend.on();
  cout << "Vending Machine is on!" << endl;

  Vend.getMenu();
  Vend.coin(100);
  cout << "money has been successfully deposited" << endl;

  Vend.choice(4);
  if (Vend.check() == true) {
    Vend.cook();
    cout << "making a drink... please wait." << endl;
  } else {
    cout << "Error, try again!" << Vend.cancel() << endl;
  }

  cout << "Take your change: " << Vend.finish() << endl;

  Vend.off();
  cout << "Shutting Down Vending Machine..." << endl;

  return 0;
}
