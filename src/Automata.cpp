// Copyright 2024 Mikhas3009

#include "../include/Automata.h"

Automata::Automata() {
    coffeMenuMap = {
        {1, {"Espresso", 100.0}},
        {2, {"Cappuccino", 150.0}},
        {3, {"Latte", 120.0}},
        {4, {"Americano", 110.0}},
        {5, {"Macchiato", 135.5}},
        {6, {"Mocha", 125.75}},
        {7, {"Ristretto", 95.25}},
    };
    currentCash = 0;
    currentState = States::OFF;
}

void Automata::on() {
    if (currentState == States::OFF) {
        Logger::log("Automata is ON");
        currentState = States::WAIT;
    }
}

void Automata::off() {
    if (currentState == States::WAIT) {
        Logger::log("Automata is OFF");
        currentState = States::OFF;
    } else {
        throw std::logic_error("Automata cannot Off right now!");
    }
}

void Automata::coin(float value) {
    if (currentState == States::WAIT) {
        currentState = States::ACCEPT;
    }
    if (currentState == States::ACCEPT) {
        currentCash += value;
        Logger::log("Money added");
        return;
    }
    throw std::logic_error("cannot ACCEPT Money");
}

void Automata::choice(int value) {
    if ((value < 0) || (value > coffeMenuMap.size() + 1))
        throw std::out_of_range("Out of range of menu");
    if (currentState == States::ACCEPT) {
        item = coffeMenuMap.at(value);
        Logger::log("Ur choice is: ");
        Logger::log(item.name);
        std::cout << " for " << item.price << std::endl;
        currentState = States::CHECK;
    } else {
        throw std::logic_error("You can't choice right now!");
    }
}

bool Automata::check() {
    if (currentState == States::CHECK) {
        if (item.price > currentCash) {
            Logger::log("insufficient funds");
            std::cout << "pay" << item.price - currentCash;
        } else {
            Logger::log("Ready to start");
        }
        return (item.price <= currentCash);
    } else {
        throw std::logic_error("No need to check");
    }
}

void Automata::cancel() {
    if (currentState == States::ACCEPT || currentState == States::CHECK) {
        std::cout << "handing over money";
        std::cout << currentCash << "₽ back" << std::endl;
        currentCash = 0;
        currentState = States::WAIT;
    } else {
        throw std::logic_error("nothing to cancel");
    }
}

void Automata::cook() {
    if (currentState == States::CHECK) {
        if (check()) {
            Logger::log("Start cooking");
            currentCash -= item.price;
            std::cout << "(handing over money ";
            std::cout << currentCash << "₽ back)" << std::endl;
            currentCash = 0;
            currentState = States::COOK;
        }
    } else {
        throw std::logic_error("It's nothing to cook now!");
    }
}

void Automata::finish() {
    if (currentState == States::COOK) {
        Logger::log("Order done!");
        currentState = States::WAIT;
    } else {
        throw std::logic_error("It's nothing to finish now!");
    }
}

void Automata::getMenu() {
    for (const auto& menuItem : coffeMenuMap) {
        std::cout << "ID: " << menuItem.first << ", Name: ";
        std::cout << menuItem.second.name;
        std::cout << ", Price: $" << menuItem.second.price << std::endl;
    }
}

int Automata::getAutomataState() {
    return currentState;
}

float Automata::getCurrentCash() {
    return currentCash;
}

MenuItem Automata::getChoice() {
    return item;
}
