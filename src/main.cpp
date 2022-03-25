// Copyright 2022 UNN-IASR

#include <iostream>
#include "Automata.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
    std::string menu[5] = {
        "black tea",
        "green tea",
        "cappuccino",
        "latte",
        "hot chocolate"
     };
    int prices[5] = { 90, 90, 120, 130, 100 };
    int customerChoice;

    Automata a1(menu, prices);

    a1.on();
    a1.coin(100);
    cin >> customerChoice;
    a1.choice(customerChoice);
    a1.off();
}
