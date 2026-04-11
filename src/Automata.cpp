#include "Automata.h"
#include <iostream>
#include <string>

Automata::Automata() {
    cash = 0.0;
    state = STATES::OFF;
    menu = {"Tea", "Coffee", "Milk"};
    prices = {15.0, 25.0, 20.0};
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        std::cout << "Automata is ON" << std::endl;
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        std::cout << "Automata is OFF" << std::endl;
    }
}

void Automata::coin(double amount) {
    if (state == STATES::WAIT ||
        state == STATES::ACCEPT) {
        cash += amount;
        state = STATES::ACCEPT;
        std::cout << "Accepted: " << amount
                  << ". Total: " << cash << std::endl;
    }
}

void Automata::etMenu() {
    if (state == STATES::WAIT ||
        state == STATES::ACCEPT) {
        std::cout << "Menu:" << std::endl;
        for (size_t i = 0; i < menu.size(); i++) {
            std::cout << i + 1 << ". "
                      << menu[i] << " - "
                      << prices[i] << std::endl;
        }
    }
}

STATES Automata::getState() {
    return state;
}

bool Automata::choice(int item) {
    if (state == STATES::ACCEPT) {
        if (item < 1 ||
            item > static_cast<int>(menu.size())) {
            std::cout << "Invalid choice" << std::endl;
            return false;
        }
        state = STATES::CHECK;
        if (check(item)) {
            cook(item);
            return true;
        }
        return false;
    }
    return false;
}

bool Automata::check(int item) {
    if (cash >= prices[item - 1]) {
        return true;
    }
    std::cout << "Not enough money. Need: "
              << prices[item - 1]
              << ", have: " << cash << std::endl;
    state = STATES::ACCEPT;
    return false;
}

void Automata::cancel() {
    if (state == STATES::WAIT ||
        state == STATES::ACCEPT ||
        state == STATES::CHECK) {
        std::cout << "Cancelled. Returning: "
                  << cash << std::endl;
        cash = 0.0;
        state = STATES::WAIT;
    }
}

void Automata::cook(int item) {
    state = STATES::COOK;
    std::cout << "Cooking: "
              << menu[item - 1] << "..." << std::endl;
    cash -= prices[item - 1];
    finish();
}

void Automata::finish() {
    if (state == STATES::COOK) {
        if (cash > 0) {
            std::cout << "Change: " << cash << std::endl;
        }
        cash = 0.0;
        state = STATES::WAIT;
        std::cout << "Done. Ready for next customer."
                  << std::endl;
    }
}