// Copyright 2022 GHA Test Team

#include "Automata.h"
#include <string>

Automata::Automata() {
    state = STATES::Off;
    menu[0] = "Black tea";
    menu[1] = "Green tea";
    menu[2] = "Lemon tea";
    menu[3] = "Milk tea";
    menu[4] = "Ginger tea";
    menu[5] = "Espresso";
    menu[6] = "Cappuccino";
    menu[7] = "Latte";
    menu[8] = "Black coffee";
    menu[9] = "Americano";

int tempprice[] = { 30, 25, 35, 40, 30, 30, 45, 40, 50, 55 };

    for (int i = 0; i < 10; i++) {
        prices[i] = tempprice[i];
}

cash = 0;
}

int Automata::on() {
    if (state == STATES::Off) {
        state = STATES::Wait;
        std::cout << "The vending machine is turning on" << std::endl;
        return 1;
    } else {
        std::cout << "The vending machine is already on" << std::endl;
        return 0;
    }
}

int Automata::off() {
    if (state == STATES::Wait) {
        state = STATES::Off;
        std::cout << "The venidng machine is turning off" << std::endl;
        return 1;
    } else {
        std::cout << "Can't turn off the machine" << std::endl;
        return 0;
    }
}

int Automata::coin(int c) {
    if ((state == STATES::Wait) || (state ==STATES::Accept)) {
        state = STATES::Accept;
        cash += c;
        std::cout << "Money is accepted" << std::endl;
        return 1;
    } else {
        std::cout << "Can't accept money yet" << std::endl;
        return 0;
    }
}

void Automata::getMenu() {
    std::cout << "Menu:" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << menu[i] << std::endl;
}
}

int Automata::getState() {
    std::cout << "State - " << state << std::endl;
    return state;
}

int Automata::choice(int c) {
    if ((state == STATES::Accept) && (c < 11)&&(c > 0)) {
        state = STATES::Check;
        std::cout << "Your choice is accepted - " << menu[c-1] << std::endl;
        chosenProduct = c-1;
        return 1;
    } else {
        std::cout << "Can't accept your choice" << std::endl;
        return 0;
    }
}

int Automata::check() {
    if (state == STATES::Check) {
        if (cash >= prices[chosenProduct]) {
            std::cout << "Payment is succesful" << std::endl;
            cash = cash - prices[chosenProduct];
            return 1;
        } else {
            std::cout << "There is not enough money" << std::endl;
            return 0;
        }
    } else {
        std::cout << "Can't check anything yet" << std::endl;
        return 0;
    }
}

int Automata::cancel() {
    if ((state == STATES::Accept) || (state == STATES::Check)) {
        std::cout << "Operation canceled" << std::endl;
        cash = 0;
        return 1;
    } else {
        std::cout << "Can't cancel operation at this moment" << std::endl;
        return 0;
    }
}

int Automata::cook() {
    if (state == STATES::Check) {
        state = STATES::Cook;
        std::cout << "Cooking chosen product..." << std::endl;
        return 1;
    } else {
        std::cout << "Can't cook product at this moment" << std::endl;
        return 0;
    }
}

int Automata::finish() {
    if (state == STATES::Cook) {
        state == STATES::Wait;
        std::cout << "Cooking is finished" << std::endl;
        return 1;
    } else {
        std::cout << "Can't finish any operation at this moment" << std::endl;
        return 0;
    }
}
