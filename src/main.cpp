// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>

int main() {
    Automata anAutomat;

    int aCash = 100;

    anAutomat.on();
    anAutomat.coin(aCash);
    anAutomat.choice(3);
    anAutomat.check();
    anAutomat.cook();
    anAutomat.finish();
}
