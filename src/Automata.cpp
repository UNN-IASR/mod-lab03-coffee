#include "Automata.h"
#include <iostream>

using namespace std;

Automata::Automata() {
    cash = 0;
    state = OFF;
    choiceIndex = -1;

    menu = {"Чай", "Коффе", "Молоко"};
    prices = {50, 100, 70};
}

Automata::~Automata() {}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        cout << "Автомат включен\n";
    }
}

void Automata::off() {
    state = OFF;
    cash = 0;
    cout << "Автомат выключен\n";
}

void Automata::coin(double amount) {
    if (state == WAIT || state == ACCEPT) {
        cash += amount;
        state = ACCEPT;
        cout << "Внесено: " << amount << ", всего: " << cash << "\n";
    }
}

void Automata::getMenu() {
    cout << "Меню:\n";
    for (int i = 0; i < menu.size(); i++) {
        cout << i << " - " << menu[i] << " (" << prices[i] << ")\n";
    }
}

Automata::STATES Automata::getState() {
    return state;
}

void Automata::choice(int index) {
    if (state == ACCEPT && index >= 0 && index < menu.size()) {
        choiceIndex = index;
        state = CHECK;
        cout << "Выбран: " << menu[index] << "\n";
    }
}

void Automata::check() {
    if (state == CHECK) {
        if (cash >= prices[choiceIndex]) {
            state = COOK;
            cout << "Достаточно денег\n";
        } else {
            cout << "Недостаточно денег\n";
            state = WAIT;
        }
    }
}

void Automata::cook() {
    if (state == COOK) {
        cout << "Готовим " << menu[choiceIndex] << "...\n";
        cash -= prices[choiceIndex];
        finish();
    }
}

void Automata::finish() {
    cout << "Готово! Остаток: " << cash << "\n";
    state = WAIT;
    choiceIndex = -1;
}

void Automata::cancel() {
    cout << "Отмена. Возврат: " << cash << "\n";
    cash = 0;
    state = WAIT;
}