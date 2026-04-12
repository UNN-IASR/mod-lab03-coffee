#include <iostream>
#include <vector>

#include "Automata.h"

int main() {
    Automata machine(
        {"Tea", "Coffee", "Cappuccino", "Milk"},
        {30, 50, 80, 25}
    );

    std::cout << "=== Hot Drinks Automata Demo ===" << std::endl;

    machine.on();
    std::cout << "Machine is on" << std::endl;

    std::cout << "\nMenu:\n" << machine.getMenu() << std::endl;

    machine.coin(100);
    std::cout << "\nInserted 100 rub." << std::endl;

    std::cout << "Selected: " << machine.choice(1) << std::endl;

    if (machine.check()) {
        std::cout << machine.cook() << std::endl;
        std::cout << machine.finish() << std::endl;
    }

    std::cout << "\nSecond session:" << std::endl;
    machine.coin(40);
    std::cout << "Inserted 40 rub." << std::endl;
    std::cout << "Refund: " << machine.cancel() << " rub." << std::endl;
    std::cout << machine.finish() << std::endl;

    machine.off();
    std::cout << "\nMachine is off" << std::endl;

    return 0;
}
