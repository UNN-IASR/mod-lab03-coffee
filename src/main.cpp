#include "../include/Automata.h"
#include <iostream>

int main() {
    Automata machine;

    std::cout << machine.getMenu() << std::endl;
    machine.on();
    std::cout << machine.getMenu() << std::endl;
    machine.coin(100);
    machine.choice(1);
    machine.check();
    machine.cook();
    machine.finish();
    machine.coin(40);
    machine.choice(2);
    machine.check();
    machine.coin(30);
    machine.check();
    machine.cook();
    machine.finish();
    machine.coin(50);
    machine.choice(4);
    machine.cancel();
    machine.off();
    machine.coin(10);

    return 0;
}
