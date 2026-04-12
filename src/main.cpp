// Copyright 2026 Your Name

#include <iostream>

#include "Automata.h"

int main() {
    Automata machine(
        {"Tea", "Coffee", "Cappuccino", "Milk"},
        {30, 50, 80, 25});

    std::cout << "Demo\n";

    machine.on();
    machine.coin(100);

    std::cout << machine.choice(1) << std::endl;

    if (machine.check()) {
        std::cout << machine.cook() << std::endl;
        std::cout << machine.finish() << std::endl;
    }

    return 0;
}
