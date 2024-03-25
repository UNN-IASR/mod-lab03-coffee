//"Copyright [year] <Copyright Owner>"
#include "Automata.h"
#include <string>
#include <map>
#include <iostream>

Automata::Automata() {
    cash = 0;
    state = Off;
    prices["black coffee"] = 30;
    prices["latte"] = 40;
    prices["cappuccino"] = 40;
    prices["black tea"] = 20;
    prices["cacao"] = 35;
}

Automata::~Automata() {}

void Automata::on() {
    if (state == Off) {
        state = Wait;
        std::cout << "Machine is on" << std::endl;
    }
}

void Automata::off() {
    if (state == Wait) {
        state = Off;
        std::cout << "\nMachine is off" << std::endl;
    }
}

void Automata::coin(int money) {
    if (state == Wait || state == Accept) {
        cash += money;
        state = Accept;
        std::cout << "\nMoney is accepted. There is " << cash << std::endl;
    }
}

void Automata::getMenu() {
    std::cout << "/nMenu" << std::endl;
    if (state == Wait || state == Accept) {
        for (const auto& element : prices)
            std::cout << element.first << "\t" << element.second << std::endl;
    }
}

states Automata::getState() {
    return state;
}

void Automata::choice(std::string name) {
    if (state == Accept) {
        if (prices.count(name) == 0) {
            std::cout << "Mistake!";
        } else {
            state = Check;
            if (check(name))
                cook(name);
            }
        }
}

bool Automata::check(std::string name) {
    if ((state == Check || state == Accept) && cash >= prices.find(name)->second)
        return true;
    state = Accept;
    return false;
}

void Automata::cancel() {
    if (state == Accept || state == Check) {
        cash = 0;
        state = Wait;
        std::cout << "\nThe order is cancelled" << std::endl;
    }
}

void Automata::cook(std::string name) {
    cash -= prices.find(name)->second;
    state = Cook;
    std::cout << "\nThe drink is cooked" << std::endl;
    finish(name);
}

void Automata::finish(std::string name) {
    std::cout << "\nYour change is " << cash << std::endl;
    std::cout << "\nYour drink " << name << " is ready!" << std::endl;
    cash = 0;
    state = Wait;
}
