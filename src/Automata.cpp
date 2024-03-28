// Copyright 2022 Yuriy Korshunov

#include "../include/Automata.h"

Automata::Automata() {
    menu = {
        {1, {"Capuccino", 150}},
        {2, {"Americano", 130}},
        {3, {"Latte", 110}},
        {4, {"Espresso", 140}},
        {5, {"Cocoa", 100}}
    };
    state = States::OFF;
    cash = 0;
    item = menu.at(1);
}

void Automata::on() {
    if (state == States::OFF) {
        state = States::WAIT;
    } else {
        throw std::logic_error("Already on");
    }
}

void Automata::off() {
    if (state == States::WAIT) {
        state = States::OFF;
    } else {
        throw std::logic_error("Unsafe to off now");
    }
}

void Automata::coin(int value) {
    if (state == States::WAIT) {
        cash += value;
        state = States::ACCEPT;
    } else if (state == States::ACCEPT) {
        cash += value;
    } else {
        throw std::logic_error("Can't get money now");
    }
}

void Automata::choice(int value) {
    if (state == States::ACCEPT) {
        item = menu.at(value);
        state = States::CHECK;
    } else {
        throw std::logic_error("Can't choice now");
    }
}

bool Automata::check() {
    if (state == States::CHECK) {
        return item.price <= cash;
    } else {
        throw std::logic_error("Nothing to check");
    }
}

void Automata::cancel() {
    if (state == States::ACCEPT || state == States::CHECK) {
        cash = 0;
        state = States::WAIT;
    } else {
        throw std::logic_error("Can't cancel now");
    }
}

void Automata::cook() {
    if (state == States::CHECK) {
        if (check()) {
            cash = 0;
            state = States::COOK;
        }
    } else {
        throw std::logic_error("Nothing to cook");
    }
}

void Automata::finish() {
    if (state == States::COOK) {
        state = States::WAIT;
    } else {
        throw std::logic_error("Nothing to finish");
    }
}

void Automata::getMenu() {
    std::cout << "Menu:" << std::endl;
    for (const auto& [key, item] : menu) {
        std::cout << key << ". " << item.name;
        std::cout << " - " << item.price << std::endl;
    }
}

int Automata::getState() {
    return state;
}

int Automata::getCash() {
    return cash;
}

Automata::menuItem Automata::getChoice() {
    return item;
}
