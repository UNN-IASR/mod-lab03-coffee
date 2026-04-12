// Copyright 2026 EnganK

#include <iostream>
#include "../include/Automata.h"
int demo() {
    Automata a;
    a.on();
    std::cout << a.etMenu();
    a.coin(50);
    a.choice(1);
    a.check();
    a.cook();
    a.finish();
    a.off();
}
