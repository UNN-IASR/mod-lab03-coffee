// Copyright 2022 GHA Test Team

#include <iostream>
#include "Automata.h"

void Work1(Automata vendingMachine){
vendingMachine.on();
vendingMachine.coin(5);
vendingMachine.choice(2);
vendingMachine.cancel();
vendingMachine.coin(20);
vendingMachine.check(2);
vendingMachine.cook(2);
vendingMachine.finish();
vendingMachine.off();
}

int main(){
setlocale(LC_ALL, "Rus");
Automata automata;
Work1(automata);
return 0;
}
