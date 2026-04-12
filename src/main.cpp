// Copyright 2022 GHA Test Team
// Copyright 2024 GHA Test Team

#include <iostream>
#include "../include/Automata.h"

void runDemo() {
    std::cout << "\n========== DEMO ==========\n";

    Automata vm;
    std::cout << "1. Start: " << stateToStr(vm.getState()) << "\n";

    vm.on();
    std::cout << "2. on(): " << stateToStr(vm.getState()) << "\n";

    vm.coin(30);
    std::cout << "3. coin(30): Balance=" << vm.getCash()
              << ", State=" << stateToStr(vm.getState()) << "\n";

    auto menu = vm.getMenu();
    std::cout << "4. menu:\n";
    for (size_t i = 0; i < menu.size(); ++i) {
        std::cout << "   " << i << ". "
                  << menu[i].first << " - "
                  << menu[i].second << "\n";
    }

    vm.choice(0);
    std::cout << "5. choice(0): " << stateToStr(vm.getState()) << "\n";

    std::cout << "6. check(): " << (vm.check() ? "enough" : "not enough")
              << "\n";

    if (!vm.check()) {
        vm.coin(20);
        std::cout << "7. coin(20): Balance=" << vm.getCash()
                  << ", State=" << stateToStr(vm.getState()) << "\n";
        vm.choice(0);
    }

    vm.cook();
    std::cout << "8. cook(): Balance=" << vm.getCash()
              << ", State=" << stateToStr(vm.getState()) << "\n";

    vm.finish();
    std::cout << "9. finish(): State=" << stateToStr(vm.getState()) << "\n";

    vm.off();
    std::cout << "10. off(): State=" << stateToStr(vm.getState()) << "\n";
    std::cout << "==========================\n";
}

int main() {
    runDemo();
    return 0;
}
