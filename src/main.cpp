// Copyright 2022 LepehinM
#include <iostream>
#include "Automata.h"
using std::string;
using std::cout;
int main() {
    Automata fastdrink;
    fastdrink.on();
    cout << "Hello, my friend";
    fastdrink.coin(100);
    int drink = fastdrink.choice("tea");
    if (fastdrink.check(drink)) {
        cout << "The cooking has begun";
        fastdrink.cook(drink);
        int change = fastdrink.finish();
        cout << "the end, your money " << change;
    } else {
        int change = fastdrink.cancel();
        cout << "sorry, your money" << change;
    }
    fastdrink.off();
    return EXIT_SUCCESS;
}
