// Copyright 2022 UNN-IASR
#include "Automata.h"
using std::cout;
using std::endl;

Automata::Automata() {
    state = OFF;
    money = 0;
    choiseCustomer = 0;
    getState();
}
void Automata::on() {
    if (state == OFF) {
        cout << "Hi,mate" << endl;
        state = WAIT;
        getMenu();
        getState();
} else {
        error();
    }
}
void Automata::off() {
    if (state == WAIT) {
        cout << "Good bye" << endl;
        state = OFF;
    } else {
        error();
    }
}
void Automata::coin(int coins) {
    if (state == WAIT) {
        state = ACCEPT;
        money += coins;
        cout << "Thank u for Donation, go ahead" << endl;
    } else {
        if (state == ACCEPT) {
            money += coins;
            cout << "Thank u for Donation, go ahead" << endl;
        } else {
            error();
        }
    }
}
void Automata::getMenu() {
    for (int i = 0; i++; i < 9) {
        cout << i+1 << menu[i] << endl;
    }
}

void Automata::getState() {
    switch (state) {
    case OFF:
        cout << "Doesn't work now" << endl;
        break;
    case WAIT:
        cout << "Press ur buttons sometimes" << endl;
        break;
    case ACCEPT:
        cout << "Give me ur money,peach!" << endl;
        break;
    case CHECK:
        cout << "Checking" << endl;
        break;
    case COOK:
        cout << "I think all is gonna good" << endl;
        break;
    }
}
void Automata::choice(int choosenOne) {
    if (state == ACCEPT) {
        if (sizeof(menu) < choosenOne || choosenOne <= 0) {
            error();
        }
        state = CHECK;
        choiseCustomer = choosenOne;
        cout << "Your choice is " << menu[choiseCustomer - 1] << endl;
        getState();
    } else {
        error();
    }
}
bool Automata::check() {
    if (state == CHECK) {
        if (money >= prices[choiseCustomer]) {
            return true;
        }
        getState();
        return false;
    } else {
        error();
        return false;
    }
}
int Automata::whereIsMyMoney() {
    cout << "Your cash is " << money << endl;
    return money;
}
void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        cout << "Give me more than i have now" << endl;
        whereIsMyMoney();
        getState();
    } else {
        error();
    }
}
void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
        money -= prices[choiseCustomer];
        whereIsMyMoney();
        getState();
    } else {
        error();
    }
}
void Automata::finish() {
        if (state == COOK) {
            state = WAIT;
            whereIsMyMoney();
            getState();
        } else {
            error();
        }
    }
void Automata::error() {
cout << "u did some wrong things " << endl;
}
