// Copyright 2022 UNN-IASR
#include "Automata.h"

Automata::Automata() {
    cash = 0;
    menu[0] = "tea";
    menu[1] = "coffee";
    menu[2] = "milk";
    prices[0] = 20.0;
    prices[1] = 50.0;
    prices[2] = 35.0;
    state = OFF;
}
void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "The automat is ON\n";
    }
}
float Automata::off() {
    float temp = 0;
    if (state == WAIT) {
        state = OFF;
        if (cash > 0) {
            std::cout << "Here is your extra cash: " << cash << "\n";
            temp = cash;
            cash = 0;
        }
        std::cout << "The automat is OFF\n";
    }
    return temp;
}
void Automata::coin(float money) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        std::cout << "Make a payment";
        cash += money;
        std::cout << "\n";
    }
}
void Automata::getMenu() {
    std::cout << "Menu:\n";
    for (int i = 0; i < sizeof(menu) / sizeof(*menu); i++) {
        std::cout << i + 1 << ") " << menu[i] << " - " << prices[i] << "\n";
    }
}
STATE Automata::getState() {
    std::cout << "Current state: ";
    switch (state) {
    case 0:
        std::cout << "OFF";
        break;
    case 1:
        std::cout << "WAIT";
        break;
    case 2:
        std::cout << "ACCEPT";
        break;
    case 3:
        std::cout << "CHECK";
        break;
    case 4:
        std::cout << "COOK";
        break;
    }
    std::cout << "\n";
    return state;
}
void Automata::choice(int d) {
    if (state == ACCEPT) {
        state = CHECK;
        std::cout << "Choose the number of a drink";
        drink = d;
        std::cout << "\n";
    }
}
bool Automata::check() {
    if (state == CHECK) {
        if (prices[drink - 1] > cash) {
            std::cout << "Not enough money. Your account: "
                << cash << ". Required: "
                << prices[drink - 1] << "\n";
            return false;
        }
        return true;
    }
    return false;
}
void Automata::cook() {
    if (state == CHECK && check() == true) {
        state = COOK;
        std::cout << "Cooking...\n";
    }
}
void Automata::finish() {
    if (state == COOK) {
        state = WAIT;
        cash -= prices[drink - 1];
        std::cout << "Cooking is finished. Enjoy your drink!\n";
    }
}
void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        std::cout << "Proccess is interrupted.\n";
    }
}
