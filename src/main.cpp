// Copyright 2022 UNN-IASR
#include <iostream>
#include "Automata.h"

using std::string;
using std::cout;

int main() {
    Automata a;
    int b;
    a.on();
    cout << "automat vkluchen!\n";
    a.coin(200);
    cout << "dengi zaneseni!\n";
    a.choice(1);
    cout << "super! gotovim!\n";
    a.finish();
    b = a.cancel();
    cout << "sdacha! " << b;
    a.off();
    cout << "\nautomat vikluchen!\n";
}
