// Copyright 2024 Danil Volkov

#include <iostream>
#include "../include/Automata.h"

int main() {
    Automata vendingMachine;

    // Scenario 1: turning on the vending machine,
    // viewing the menu, buying a drink

    vendingMachine.on();
    vendingMachine.getMenu();
    vendingMachine.coin(100);
    vendingMachine.choice(1);

    // Scenario 2: Insufficient funds
    std::cout << std::endl;
    vendingMachine.coin(10);
    vendingMachine.choice(8);

    // Scenario 3: Depositing additional funds
    std::cout << std::endl;
    vendingMachine.coin(10);
    vendingMachine.choice(8);
    vendingMachine.coin(80);
    vendingMachine.choice(8);

    // Scenario 4: interruption of the machine operation
    std::cout << std::endl;
    vendingMachine.coin(10);
    vendingMachine.cancel();

    // Scenario 5: unavailable transition
    std::cout << std::endl;
    std::cout << vendingMachine.getState() << std::endl;
    vendingMachine.choice(6);

    // Scenario 6: turning off the machine
    std::cout << std::endl;
    vendingMachine.off();

    return 0;
}
