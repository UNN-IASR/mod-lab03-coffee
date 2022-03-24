// Copyright 2022 UNN-IASR
#include "../include/Automata.h"

Automata::Automata() {
    myState = STATES::OFF;
    myMenu = {
        "Twix",
        "Mars",
        "Milk",
        "Powerade",
        "Тульский пряник",
        "Snikers",
        "Круассан 7-days",
        "Lays",
        "Хрусteam",
        "Архыз"
    };
    myPrices = { 60, 50, 70, 110, 80,
                 60, 60, 70, 40, 50 };
    myCash = 0;
}

void Automata::getMenu() {
    std::cout << "Menu:" <<std::endl;

    for (auto&& product : myMenu) {
        std::cout << product << std::endl;
    }

    std::cout << std::endl;
}

int Automata::getState() {
    return myState;
}

void Automata::on() {
    if (myState == STATES::OFF) {
        std::cout << "The machine is starting..." << std::endl;

        getState();
        getMenu();

        myState = STATES::WAIT;
    } else {
        throw std::logic_error("The machine has already started.");
    }
}

void Automata::off() {
    if (myState == STATES::OFF) {
        std::cout << "Turn off..." << std::endl;

        myState = STATES::OFF;
    } else {
        throw std::logic_error("Unsafe shutdown has aborted.");
    }
}

void Automata::coin(const int theCoin) {
    if (myState == STATES::WAIT) {
        std::cout << "The money is put!" << std::endl;

        myState = STATES::ACCEPT;
        myCash += theCoin;
    } else {
        throw std::logic_error("It's not the time to put money in.");
    }
}

void Automata::cancel() {
    if (myState == STATES::ACCEPT || myState == STATES::CHECK) {
        std::cout
        << "Operation canceled. The money will be refunded..."
        << std::endl;

        myState = STATES::WAIT;
        myCash = 0;
    } else {
        throw
        std::logic_error("The operation cannot be canceled.");
    }
}

void Automata::choice(const int theNumber) {
    if (myState == STATES::ACCEPT) {
        std::cout << "The choice was accepted..." << std::endl;

        myState = STATES::CHECK;
    } else {
        throw
        std::logic_error("The operation cannot be canceled.");
    }
}

void Automata::check() {
    if (myState == STATES::CHECK) {
        std::cout << "Check..." << std::endl;

        if (myCash >= myPrices.at(myChoice)) {
            std::cout << "Successfully!" << std::endl;

            myCash -= myPrices.at(myChoice);
        } else {
            std::cout << "Not enough money.." << std::endl;
        }
    } else {
        std::cout << "Verification is not possible.." << std::endl;
    }
}

void Automata::cook() {
    if (myState == STATES::CHECK) {
        std::cout << "Cooking..." << std::endl;

        myState = STATES::COOK;
    } else {
        throw
        std::logic_error("This operation is not possible at this stage...");
    }
}

void Automata::finish() {
    if (myState == STATES::COOK) {
        std::cout << "Finish... Take the food." << std::endl;

        myState = STATES::WAIT;
    } else {
        throw
        std::logic_error("This operation is not possible at this stage...");
    }
}
