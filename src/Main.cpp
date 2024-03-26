// Copyright 2024 Kokorin Alexandr

#include <iostream>
#include "Automata.h"

int main() {
setlocale(LC_ALL, "Rus");
Automata vendingMachine;

vendingMachine.on();
vendingMachine.coin(5);
vendingMachine.choice(2);
vendingMachine.cancel();
vendingMachine.coin(20);
vendingMachine.check(2);
vendingMachine.cook(2);
vendingMachine.finish();
vendingMachine.off();

return 0;
}