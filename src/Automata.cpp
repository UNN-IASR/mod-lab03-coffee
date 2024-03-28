// Copyright 2024 Nekkozzz

#include "../include/Automata.h"

Automata::Automata() {
    menu = {
        { 1, { "Espresso", 100 } },
        { 2, { "Americano", 120 } },
        { 3, { "Doppio", 150 } },
        { 4, { "Cappuccino", 200 } },
        { 5, { "Flat-white", 170 } },
        { 6, { "Latte", 200 } },
        { 7, { "Raf", 190 } },
        { 8, { "Moccachino", 230 } },
        { 9, { "Macchiato", 170 } },
        { 10, { "Beaumont", 150 } },
        { 11, { "Frappe", 200 } },
        { 12, { "Frappuccino", 210 } },
    };
    state = states::OFF;
    cash = 0;
    item = menu.at(1);
}
void Automata::log(const std::string value) {
    std::cout << value << std::endl;
}

void Automata::on() {
    if (state == states::OFF) {
        log("I'm alive");
        state = states::WAIT;
    } else {
        throw std::logic_error("I'm already alive!");
    }
}
void Automata::off() {
    if (state == states::WAIT) {
        log("I'm going to sleep a little");
        state = states::OFF;
    } else {
        throw std::logic_error("It's unsafe to off me now!");
    }
}
void Automata::coin(const float value) {
    switch (state) {
    case states::WAIT:
        state = states::ACCEPT;
        log("Im eating money now");
    case states::ACCEPT:
        cash += static_cast<float>(value);
        std::cout << "It's " << cash << "₽ now" << std::endl;
        break;
    default:
        throw std::logic_error("I can't eat money now!");
    }
}
void Automata::choice(const int value) {
    if (!(0 < value && value < menu.size()+1))
        throw std::out_of_range("I don't have that much food now!");
    if (state == states::ACCEPT) {
        item = menu.at(value);
        std::cout << "Your choice is " << item.name;
        std::cout << " for " << item.price << "₽" << std::endl;
        state = states::CHECK;
    } else {
        throw std::logic_error("You can't choice anything now!");
    }
}
bool Automata::check() {
    if (state == states::CHECK) {
        if (item.price > cash) {
            log("You need to go back and give me more money");
            std::cout << "(just " << item.price - cash;
            std::cout << "₽ more)" << std::endl;
        } else {
            log("I'm ready to cook now");
        }
        return !(item.price > cash);
    } else {
        throw std::logic_error("It's nothing to check now!");
    }
}
void Automata::cancel() {
    if (state == states::ACCEPT || state == states::CHECK) {
        std::cout << "Okay I'll just give you your ";
        std::cout << cash << "₽ back" << std::endl;
        cash = 0;
        state = states::WAIT;
    } else {
        throw std::logic_error("Sorry you can't cancel it!");
    }
}
void Automata::cook() {
    if (state == states::CHECK) {
        if (check()) {
            log("So I'm cooking now");
            cash -= item.price;
            std::cout << "(i also give your ";
            std::cout << cash << "₽ back)" << std::endl;
            cash = 0;
            state = states::COOK;
        }
    } else {
        throw std::logic_error("It's nothing to cook now!");
    }
}
void Automata::finish() {
    if (state == states::COOK) {
        log("Come on take your food now");
        state = states::WAIT;
    } else {
        throw std::logic_error("It's nothing to finish now!");
    }
}

void Automata::getMenu() {
    for (const auto& [key, item] : menu) {
        std::cout << key << ". " << item.name;
        std::cout << " - " << item.price << std::endl;
    }
}
int Automata::getState() {
    return state;
}
float Automata::getCash() {
    return cash;
}
Automata::menu_item Automata::getChoice() {
    return item;
}
