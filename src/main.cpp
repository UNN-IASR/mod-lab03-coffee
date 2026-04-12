// Copyright 2022 UNN-IASR

#include <iostream>

#include "Automata.h"

int main() {
    Automata a;

    a.on();
    a.coin(100);
    a.getMenu();

    a.choice(1);
    if (a.check()) {
        a.cook();
        a.finish();
        std::cout << "Drink ready!" << std::endl;
    } else {
        std::cout << "Not enough money!" << std::endl;
    }

    return 0;
}
