// Copyright 2024 Mikhas3009

#include "../include/Automata.h"

int main() {
    Automata coffee;
    coffee.on();
    coffee.coin(100);
    coffee.choice(1);
    coffee.cancel();
    coffee.coin(150);
    coffee.choice(1);
    coffee.check();
    coffee.cook();
    coffee.finish();
    coffee.off();
}
