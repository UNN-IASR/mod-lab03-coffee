// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

Automata::Automata() {
    stateOfAutomata = OFF;
    cash = 0;
    menu = {
        "Black tea",
        "Green tea",
        "Americano",
        "Cappuccino",
        "Latte",
        "Espresso",
        "Hot water"
    };
    prices = { 50, 50, 120, 100, 125, 75, 25 };
    positionOfCheak = -1;
}

    void Automata::getMenu() {
        cout << "Menu of Automata" << endl;
        for (int i = 0; i < MENU_DIMENSION; i++) {
            cout << i + 1 << " position: " << menu[i] << endl;
        }
    }

    void Automata::printInfoAboutState() {
        switch (stateOfAutomata) {
        case OFF:
            cout << "Automata is off" << endl;
            break;
        case WAIT:
            cout << "Automata is ready to take order" << endl;
            break;
        case ACCEPT:
            cout << "Replenish the balance and select the menu item" << endl;
            break;
        case CHEAK:
            cout << "Financial check" << endl;
            break;
        case COOK:
            cout << "The machine starts cooking" << endl;
            break;
        default:
            break;
        }
    }

    void Automata::choice(int position) {
        if (position <= MENU_DIMENSION && position > 0) {
            if (stateOfAutomata == ACCEPT) {
                stateOfAutomata = CHEAK;
                positionOfCheak = position - 1;
            }
        } else {
            cout << "Invalid value entered" << endl;
        }
        printInfoAboutState();
    }

    STATES Automata::getState() {
        return stateOfAutomata;
    }

    void Automata::on() {
        if (stateOfAutomata == OFF) {
            stateOfAutomata = WAIT;
            getMenu();
        }
        printInfoAboutState();
    }

    void Automata::off() {
        if (stateOfAutomata == WAIT) {
            stateOfAutomata = OFF;
        }
        printInfoAboutState();
    }

    void Automata::coin(double depositedAmount) {
        if (stateOfAutomata == WAIT || stateOfAutomata == ACCEPT) {
            stateOfAutomata = ACCEPT;
            cash += depositedAmount;
        }
        printInfoAboutState();
    }

    void Automata::check() {
        if (stateOfAutomata == CHEAK) {
            cout <<"---"<< cash << endl;
            if (cash >= prices[positionOfCheak]) {
                stateOfAutomata = COOK;
            } else {
                cout << "Not enough" <<endl;
                positionOfCheak = -1;
                stateOfAutomata = WAIT;
            }
        }
        printInfoAboutState();
    }

    int Automata::cancel() {
        if (stateOfAutomata == ACCEPT || stateOfAutomata == CHEAK) {
            positionOfCheak = -1;
            stateOfAutomata = WAIT;
            double change = cash;
            cash = 0;
            printInfoAboutState();
            return change;
        }
        return -1;
    }

    void Automata::cook() {
        if (stateOfAutomata == COOK) {
            cash -= prices[positionOfCheak];
            cout << "Processing..." << endl;
        }
    }

    double Automata::getCash() {
        return cash;
    }

    void Automata::finish() {
        if (stateOfAutomata == COOK) {
            stateOfAutomata = WAIT;
        }
        printInfoAboutState();
    }
