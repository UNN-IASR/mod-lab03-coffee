// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>
#include <string>
int main() {
    Automata ak47;
    ak47.on();
    ak47.coin(47);
    ak47.choice(3);
    if (ak47.check()) {
        ak47.cook();
        ak47.finish();
    } else {
        ak47.cancel();
    }
    ak47.off();
    return 0;
}
