// Copyright 2022 Yuriy Korshunov

#include "../include/Automata.h"

int main() {
    Automata coffee;
    coffee.on();
    coffee.coin(150);
    coffee.choice(2);
    coffee.cancel();
    coffee.coin(150);
    coffee.choice(3);
    coffee.check();
    coffee.cook();
    coffee.finish();
    coffee.off();
    coffee.getMenu();
}
