#include "../include/Automata.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");

    Automata machine;

    std::cout << "=== —имул€ци€ работы кофемашины ===" << std::endl;

    machine.on();
    machine.getMenu();

    machine.coin(50);
    machine.coin(60);

    int myChoice = 3;

    machine.choice(myChoice);
    machine.cook(myChoice);
    machine.finish();

    machine.off();

    return 0;
}