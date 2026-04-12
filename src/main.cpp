// Copyright 2026 UNN-IASR
#include "Automata.h"
#include <iostream>

int main()
{
    std::cout << "Example 1\n" << std::endl;
    Automata a;
    a.on();
    std::cout << a.getMenu();
    a.coin(100);
    a.choice(3);
    std::cout << "\nExample 2\n" << std::endl;
    a.on();
    std::cout << a.getMenu();
    a.coin(50);
    a.choice(4);
    a.coin(15);
    a.off();
}
