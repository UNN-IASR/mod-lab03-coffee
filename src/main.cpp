// Copyright 2026 HirGior
#include "Automata.h"

int main() {
    Automata a;

    a.on();
    a.getMenu();

    a.coin(100);
    a.choice(1); // Coffee
    a.check();
    a.cook();
    a.finish();

    a.off();

    return 0;
}
