#include "../include/Automata.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>

Automata::Automata() : state(STATES::OFF), cash(0), selectedItem(-1) {
    menu = { "Espresso", "Americano", "Cappuccino", "Latte", "Hot chocolate", "Black tea", "Green tea" };
    prices = { 50, 60, 70, 80, 65, 50, 50 };
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        cash = 0;
        selectedItem = -1;
        std::cout << "Coffee machine is ON. State: WAIT" << std::endl;
    }
    else {
        std::cout << "Coffee machine is already ON." << std::endl;
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        cash = 0;
        selectedItem = -1;
        state = STATES::OFF;
        std::cout << "Coffee machine is OFF." << std::endl;
    }
    else {
        std::cout << "Coffee machine can OFF only from state: WAIT." << std::endl;
    }
}

void Automata::coin(int amount) {
    if (amount <= 0) {
        std::cout << "The amount maybe only positive." << std::endl;
        return;
    }
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        state = STATES::ACCEPT;
        cash += amount;
        std::cout << "Accepted: " << amount << " rub. Balance: " << cash << " rub." << std::endl;
    }
    else {
        std::cout << "Coins are accepted only on WAIT or ACCEPT states." << std::endl;
    }
}

std::string Automata::getMenu() const {
    if (state != STATES::OFF) {
        std::string result = "Menu: \n";
        for (size_t i = 0; i < menu.size(); i++) {
            result += std::to_string(i + 1) + ". " + menu[i] + " - " + std::to_string(prices[i]) + " rub\n";
        }
        return result;
    }
    else
    {
        return "Coffee machine is OFF - menu is unavailable.\n";
    }
}

STATES Automata::getState() const {
    return state;
}

bool Automata::choice(int menuNumber) {
    if (state != STATES::ACCEPT) {
        std::cout << "The choice of a drink is possible only from state: ACCEPT" << std::endl;
        return false;
    }
    if (menuNumber < 1 || menuNumber > static_cast<int>(menu.size())) {
        std::cout << "Incorrect drink number. Please enter a number from 1 to " << menu.size() << std::endl;
        return false;
    }
    int index = menuNumber - 1;
    selectedItem = index;
    state = STATES::CHECK;
    std::cout << "Your choice: " << menu[index] << " for " << prices[selectedItem] << " rub" << std::endl;
    return true;
}

bool Automata::check() {
    if (state != STATES::CHECK) return false;
    if (cash >= prices[selectedItem]) {
        std::cout << "There are enough coins, I start cooking." << std::endl;
        state = STATES::COOK;
        return true;
    }
    else {
        std::cout << "Coins are not enough." << std::endl;
        state = STATES::ACCEPT;
        return false;
    }
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        if (cash > 0) {
            std::cout << "Refund of coins: " << cash << std::endl;
            cash = 0;
        }
        state = STATES::WAIT;
        selectedItem = -1;
    }
    else {
        std::cout << "Cancellation is not possible from the current state." << std::endl;
    }
}

void Automata::cook() {
    if (state == STATES::COOK) {
        std::cout << "Cooking " << menu[selectedItem] << "..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "Drink is ready!" << std::endl;
    }
    else {
        std::cout << "Cooking is not possible from the current state." << std::endl;
    }
}

void Automata::finish() {
    if (state == STATES::COOK) {
        int price = prices[selectedItem];
        if (cash >= price) {
            int change = cash - price;
            if (change > 0) {
                std::cout << "Change returned: " << change << " rub" << std::endl;
            }
            cash = 0;
        }
        selectedItem = -1;
        state = STATES::WAIT;
        std::cout << "Service finished. State: WAIT" << std::endl;
    }
    else {
        std::cout << "Finish is not possible from the current state." << std::endl;
    }
}

int Automata::getCash() const {
    return cash;
}

int Automata::getSelectedItem() const {
    return selectedItem;
}
