// Copyright 2022 Rastuharem
#include <iostream>
#include "Automata.h"

using namespace std;

int main()
{
    Automata DrinkMachine;
    DrinkMachine.on();
    cout << "Machine is on!" << '\n';
    DrinkMachine.coin(50);
    int drink = DrinkMachine.choice("Black tea");
    if (DrinkMachine.check(drink)) {
        cout << "Order accepted!"<<'\n';
        DrinkMachine.cook(drink);
        int change = DrinkMachine.finish();
        cout << "Drink is ready! Please, take your change: " << change << '\n';
    } else {
        int change = DrinkMachine.cancel();
        cout << "Your order is cancelled :(. Please, take your change: " << change << '\n';
    }
    DrinkMachine.off();
    cout << "Machine is shutting down..." << '\n';
    return EXIT_SUCCESS;
}
