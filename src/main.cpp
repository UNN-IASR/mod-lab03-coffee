// Copyright 2022 GHA Test Team

#include <iostream>
#include "Automata.h"

int main() {
    Automata example;

    int yourCash = 50;

    example.on();
    example.coin(yourCash);
    example.choice(9);
    example.check();
    example.cook();
    example.finish();
}
