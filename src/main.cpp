#include "Automata.h"
#include <iostream>

int main() {
    Automata coffeeMachine;

    std::cout << "=== Coffee Machine Simulation ===\n";

    coffeeMachine.on();
    std::cout << "Machine is ON. State: " << static_cast<int>(coffeeMachine.getState()) << "\n";

    std::cout << "\nMenu:\n" << coffeeMachine.getMenu();

    coffeeMachine.coin(100.0);
    std::cout << "\nInserted 100 rub. Cash: " << coffeeMachine.getCash() << " rub\n";

    coffeeMachine.choice(2);
    std::cout << "Selected coffee. State: " << static_cast<int>(coffeeMachine.getState()) << "\n";

    coffeeMachine.cook();
    std::cout << "Cooking...\n";

    coffeeMachine.finish();
    std::cout << "Coffee ready! Cash left: " << coffeeMachine.getCash() << " rub\n";

    coffeeMachine.off();
    std::cout << "Machine is OFF. State: " << static_cast<int>(coffeeMachine.getState()) << "\n";

    return 0;
}