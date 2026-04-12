#include "Automata.h"
#include <iostream>

void runDemo()
{
    std::cout << "\n========== DEMO ==========\n";

    Automata vm;
    std::cout << "1. Start: " << stateToStr(vm.getState()) << "\n";

    vm.on();
    std::cout << "2. on(): " << stateToStr(vm.getState()) << "\n";

    vm.coin(30);
    std::cout << "3. coin(30): Balance=" << vm.getCash() << ", State=" << stateToStr(vm.getState()) << "\n";

    vm.coin(20);
    std::cout << "4. coin(20): Balance=" << vm.getCash() << ", State=" << stateToStr(vm.getState()) << "\n";

    auto menu = vm.getMenu();
    std::cout << "5. Menu: ";
    for (const auto &item : menu)
    {
        std::cout << item.first << "(" << item.second << ") ";
    }
    std::cout << "\n";

    vm.choice(0);
    std::cout << "6. choice(0): State=" << stateToStr(vm.getState()) << "\n";

    std::cout << "7. check(): " << (vm.check() ? "OK" : "FAIL") << "\n";

    vm.cook();
    std::cout << "8. cook(): Balance=" << vm.getCash() << ", State=" << stateToStr(vm.getState()) << "\n";

    vm.finish();
    std::cout << "9. finish(): State=" << stateToStr(vm.getState()) << "\n";

    vm.off();
    std::cout << "10. off(): State=" << stateToStr(vm.getState()) << "\n";
    std::cout << "==========================\n";
}

int main()
{
    runDemo();
    return 0;
}