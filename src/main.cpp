#include <iostream>
#include "Automata.h"

int main() {
    Automata a;

    std::cout << "--- Scenario 1: Buy coffee ---"
              << std::endl;
    a.on();
    a.coin(10.0);
    a.coin(20.0);
    a.etMenu();
    a.choice(2);

    std::cout << "\n--- Scenario 2: Cancel ---"
              << std::endl;
    a.coin(15.0);
    a.cancel();

    std::cout << "\n--- Scenario 3: Not enough money ---"
              << std::endl;
    a.coin(5.0);
    a.etMenu();
    a.choice(3);

    std::cout << "\n--- Scenario 4: Buy tea with change ---"
              << std::endl;
    a.coin(20.0);
    a.etMenu();
    a.choice(1);

    a.off();
    return 0;
}