#include "/include/Automata.h"
#include <sstream>

Automata::Automata() {
    cash = 0;
    state = OFF;

    menu = { "Tea", "Coffee", "Milk" };
    prices = { 1.5, 2.0, 1.0 };
}

void Automata::on() {
    state = WAITING_FOR_COIN;
}

void Automata::off() {
    state = OFF;
    cash = 0;
}

void Automata::coin(double amount) {
    if (state == WAITING_FOR_COIN || state == WAITING_FOR_CHOICE) {
        cash += amount;
        state = WAITING_FOR_CHOICE;
    }
}

string Automata::getMenu() {
    stringstream out;

    for (int i = 0; i < menu.size(); i++) {
        out << i << ": " << menu[i]
            << " - " << prices[i] << "\n";
    }

    return out.str();
}


STATES Automata::getState() {
    return state;
}

double Automata::getCash() {
    return cash;
}

bool Automata::check(int index) {
    return cash >= prices[index];
}

void Automata::choice(int index) {
    if (state != WAITING_FOR_CHOICE) return;

    if (check(index)) {
        state = COOKING;
        cook();
    }
    else {
        state = WAITING_FOR_COIN;
    }
}

void Automata::cook() {
    state = FINISHED;
}

void Automata::finish() {
    cash = 0;
    state = WAITING_FOR_COIN;
}

void Automata::cancel() {
    cash = 0;
    state = WAITING_FOR_COIN;
}
