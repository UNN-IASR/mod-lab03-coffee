// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main() {
    Automata automat;
    automat.on();
    cout << "automat is waiting" << endl;
    automat.coin(5);
    cout << "incerted 5 tugriks" << endl;
    automat.coin(10);
    cout << "incerted 10 tugriks" << endl;
    automat.etMenu();
    cout << "menu shown" << endl;
    automat.choice("fried nails");
    cout << "user selected fried nails" << endl;
    automat.check();
    cout << "automat checked cash" << endl;
    automat.cook();
    cout << "automat cooked nails" << endl;
    automat.finish();
    cout << "automat finished work" << endl;
}
