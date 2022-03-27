// Copyright 2022 UNN-IASR
#include <iostream>
#include <string>
#include "Automata.h"


int main() {
    Automata machine;
    machine.on();
    machine.coin(100);
    machine.getMenu();
    machine.getState();
    machine.choice("Latte");
    if (machine.check(1)) {
        machine.cook(1);
        machine.finish();
    } else {
        machine.cancel();
    }
    machine.off();
    return 0;
}
