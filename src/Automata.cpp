// Copyright 2026 UNN-IASR
#include "Automata.h"
#include <iostream>
#include <sstream>
#include <string>
Automata::Automata() {
    cash = 0;
    menu = { "Tea", "Coffee", "Milk", "Hot chocolate", "Mulled wine" };
    prices = { 50, 60, 50, 65, 60 };
    state = STATES::OFF;
    selectedDrink = -1;
}
void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        std::cout << "The vending machine is working."
            << " Make a payment and choose a drink" << std::endl;
    } else {
        std::cout << "The machine is already on!" << std::endl;
    }
}
void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        std::cout << "The machine turned off" << std::endl;
    } else {
        std::cout << "You cannot turn off the machine"
            << "in its current state!" << std::endl;
    }
}
void Automata::coin(int money) {
    if (money <= 0) {
        std::cout << "Money must be a positive number!" << std::endl;
        return;
    }
    if (state == STATES::WAIT) {
        cash += money;
        state = STATES::ACCEPT;
        std::cout << "The machine accepts money. Introduced: "
            << money << " rubles'. Balance: " << cash << std::endl;
    }
    else if (state == STATES::ACCEPT) {
        cash += money;
        std::cout << "The machine accepts money. Introduced: "
            << money << " rubles'. Balance: " << cash << std::endl;
    }
    else if (state == STATES::CHECK) {
        cash += money;
        std::cout << "The machine accepts money. Introduced: "
            << money << " rubles'. Balance: " << cash << std::endl;
        check();
    } else {
        std::cout << "You cannot deposit money "
            << "in the current state!" << std::endl;
    }
}
std::string Automata::getMenu() {
    std::stringstream ss;
    ss << "\nMenu\n";
    for (size_t i = 0; i < menu.size(); i++) {
        ss << i + 1 << ". " << menu[i] << " : " << prices[i] << " rubles'.\n";
    }
    ss << "\n";
    return ss.str();
}
STATES Automata::getState() {
    return state;
}
void Automata::choice(int numDrink) {
    if (numDrink < 0 || numDrink >= static_cast<int>(menu.size())) {
        std::cout << "Wrong choice of drink! Try again" << std::endl;
        return;
    }
    if (state == STATES::ACCEPT) {
        selectedDrink = numDrink;
        state = STATES::CHECK;
        std::cout << "Drink selected: " << menu[numDrink]
            << "; Cost: " << prices[numDrink] << std::endl;
        check();
    } else {
        std::cout << "You cannot select a drink"
            << "in its current state!" << std::endl;
    }
}
bool Automata::check() {
    if (state == STATES::CHECK) {
        if (cash >= prices[selectedDrink]) {
            std::cout << "There are enough funds."
                << "We begin the preparation of the drink." << std::endl;
            state = STATES::COOK;
            cook();
            return true;
        } else {
            std::cout << "There are not enough funds!" << std::endl;
            return false;
        }
    }
    return false;
}
void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        state = STATES::WAIT;
        cash = 0;
        selectedDrink = -1;
        std::cout << "The order has been cancelled! "
            << "The money has been refunded. " << std::endl;
    } else {
        std::cout << "The order cannot be cancelled "
            << "in the current state!" << std::endl;
    }
}
void Automata::cook() {
    if (state == STATES::COOK) {
        std::cout << "We are preparing your drink. "
            << "It may take some time..." << std::endl;
        std::cout << "..." << std::endl;
        std::cout << "..." << std::endl;
        std::cout << "The drink is ready! Thanks for waiting!" << std::endl;
        finish();
    } else {
        std::cout << "The drink cannot be prepared "
            << "in its current state!" << std::endl;
    }
}
void Automata::finish() {
    if (state == STATES::COOK) {
        state = STATES::WAIT;
        int change = cash - prices[selectedDrink];
        cash = 0;
        selectedDrink = -1;
        std::cout << "Take your drink. Change: "
            << change << " rubles'." << std::endl;
    } else {
        std::cout << "The operation cannot be performed "
            << "in the current state!" << std::endl;
    }
}
