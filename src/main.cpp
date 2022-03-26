// Copyright 2022 UNN-IASR
#include <iostream>
#include "Automata.h"

using std::string;

int main() {
    Automata machine = Automata();
    machine.on();
    machine.getMenu();
    machine.coin(20);
    machine.choice(1);
    machine.finish();
    machine.coin(10);
    machine.coin(20);
    machine.choice(3);
    machine.finish();
    machine.off();
    return 0;
}
