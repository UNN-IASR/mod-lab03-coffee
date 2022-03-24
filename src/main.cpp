// Copyright 2022 UNN-IASR

#include <iostream>
#include "Automata.h"

using std::string;
using std::cout;
using std::endl;

int main() {
    Automata machine;

    machine.getMenu();

    machine.on();
    cout << "The hot drinks machine is on!" << endl;

    machine.coin(50);
    machine.coin(50);
    machine.coin(100);
    cout << "The money has been deposited!" << endl;

    machine.choice(3);
    if (machine.check()) {
        machine.cook();
        cout << "The drink is being prepared!" << endl;
    } else {
        cout << "Try again! Returned " << machine.cancel() << endl;
    }

    cout << "Your change: " << machine.finish() << endl;

    machine.off();
    cout << "The hot drinks machine is off!" << endl;

    return 0;
}
