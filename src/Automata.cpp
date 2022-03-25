// Copyright 2022 UNN-IASR
#include "Automata.h"
using std::cout;
using std::endl;


Automata::Automata(std::string *menuDrinks, int *pricesDrinks) {
    for (int i = 0; i < 5; i++) {
        menu[i] = menuDrinks[i];
        prices[i] = pricesDrinks[i];
    }
    cash = 0;
    state = OFF;
}

void Automata::on() {
    if (state == OFF || WAIT) {
        state = WAIT;
        cout << "The Automata is working!" << endl;
        getMenu();
        cout << "Choose a drink and put money in the Automata " << endl;
    } else {
        cout << "Sorry, you can't do this action now" << endl;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        cout << "Turning off..." << endl;
    } else {
        cout << "Sorry, you can't do this action now" << endl;
    }
}

void Automata::coin(int coins) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += coins;
        cout << "Counting your money" << endl;
        cout << "The balance is " << cash<< endl;
        cout << "Press number of selected drink" << endl;
    } else {
        cout << "Sorry, you can't do this action now" << endl;
    }
}

void Automata::getMenu() {
    for (int i = 0; i < 5; i++) {
        cout << i << " - Drink: " << menu[i] <<
            " price:  " << prices[i] << endl;
    }
}

STATES Automata::getState() {
    cout << "The : Automata is in state " << state << endl;
    return state;
}

void Automata::choice(int drinkNumber) {
    if (state == ACCEPT) {
        state = CHECK;
        cout << "Processing your choice" << endl;
        check(drinkNumber);
    } else {
        cout << "Sorry, you can't do this action now" << endl;
    }
}

void Automata::check(int drinkNumber) {
    if (state == CHECK) {
        if (prices[drinkNumber] == cash) {
            state = COOK;
            cout << "Everything is correct, just wait" << endl;
            cook();
            cash = 0;
        } else {
            state = ACCEPT;
            cout << "Please, put the correct sum of money!" << endl;
        }
    } else {
        cout << "Sorry, you can't do this action now" << endl;
    }
}

void Automata::cancel() {
    if (state == CHECK || state == ACCEPT) {
        cash = 0;
        state = WAIT;
        cout << "Please, take your money back!" << endl;
    } else if (state == COOK) {
        cout << "Sorry you can't stop the process now" << endl;
    }
}

void Automata::cook() {
    if (state == COOK) {
        cout << "Your drink is cooking" << endl;
        finish();
    } else {
        cout << "Sorry, you can't do this action now" << endl;
    }
}

void Automata::finish() {
    if (state == COOK) {
        state = WAIT;
        cout << "Your drink is ready. Take it!" << endl;
        cout << "Ending the process..." << endl;
        on();
    } else {
        cout << "Sorry, you can't do this action now" << endl;
    }
}
