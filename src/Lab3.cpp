
// Copyright 2024 StatsenkoArs

#include "Automata.h"

int main() {
    std::vector <std::string> states =
    { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
    Automata cof;
    std::cout << states[cof.getState()] << std::endl;
    std::cout << "Switching on" << std::endl;
    cof.on();
    std::cout << states[cof.getState()] << std::endl;
    std::cout << "What is on the menu" << std::endl;
    std::vector <std::string> menu = cof.getMenu();
    for (std::string s : menu) {
        std::cout << s << std::endl;
    }
    std::cout << "I want coffee. Let's add some coins" << std::endl;
    cof.coin();
    std::cout << states[cof.getState()] << std::endl;
    cof.coin();
    std::cout << states[cof.getState()] << std::endl;
    std::cout << "Hehe, let's try to buy"
        "coffee with only 2 coins." << std::endl;
    cof.choice("Coffee");
    std::cout << states[cof.getState()] << std::endl;
    std::cout << "Hmmm, nothing. Okay then. I'll buy tea" << std::endl;
    cof.choice("Tea");
    std::cout << states[cof.getState()] << std::endl;
    std::cout << "Yummy. Let's turn it off" << std::endl;
    cof.off();
    std::cout << states[cof.getState()] << std::endl;
    return 0;
}
