#include "Automata.h"
using std::cout;
using std::endl;

Automata::Automata() {
    cash = 0;
    menu = new std::string[11];
    menu[0] = "Strawberry Latte";
    menu[1] = "Peach Raf";
    menu[2] = "Mango Cappuccino";
    menu[3] = "Passion Fruit Lemonade";
    menu[4] = "Watermelon Lemonade";
    menu[5] = "Classic Milkshake";
    menu[6] = "Chocolate Milkshake";
    menu[7] = "Banana Milkshake";
    menu[8] = "Water";
    menu[9] = "Assorted Cupcakes";
    menu[10] = "Assorted Ice cream";
    prices = new int[11];
    prices[0] = 150;
    prices[1] = 170;
    prices[2] = 180;
    prices[3] = 120;
    prices[4] = 120;
    prices[5] = 160;
    prices[6] = 160;
    prices[7] = 160;
    prices[8] = 50;
    prices[9] = 110;
    prices[10] = 90;
    state = OFF;
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
    }
}

void Automata::coin(const int coins) {
    if (state == WAIT) {
        state = ACCEPT;
    }
    cash = cash + coins;
}

void Automata::getMenu() {
    for (int i = 0; i < 11; i++) {
        cout << menu[i] << " - " << prices[i] << "р." << endl;
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(const int Numchoice) {
    if (state == ACCEPT) {
        state = CHECK;
        option = Numchoice;
    }
}

void Automata::check() {
    if (state == CHECK) {
        if (cash - prices[option - 1] >= 0)
            cook();
        else
            state = ACCEPT;
    }
}

void Automata::cancel() {
    if (state == CHECK || state == ACCEPT) {
        cash = 0;
        state = WAIT;
    }
    else {
        cout << "The operation cannot be canceled now" << endl;
    }
}

void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
    }
}

void Automata::finish() {
    state = WAIT;
    cash = cash - prices[option - 1];
    option = -1;
}
