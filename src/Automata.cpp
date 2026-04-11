#include "Automata.h"
#include <iostream>

Automata::Automata() {
  cash = 0;
  state = OFF;
  choiceIndex = -1;

  menu = {"Tea", "Coffee", "Milk"};
  prices = {50, 100, 70};
}

Automata::~Automata() {}

void Automata::on() {
  if (state == OFF) {
    state = WAIT;
    std::cout << "Machine turned on\n";
  }
}

void Automata::off() {
  state = OFF;
  cash = 0;
  std::cout << "Machine turned off\n";
}

void Automata::coin(double amount) {
  if (state == WAIT || state == ACCEPT) {
    cash += amount;
    state = ACCEPT;
    std::cout << "Inserted: " << amount << ", total: " << cash << "\n";
  }
}

void Automata::getMenu() {
  std::cout << "Menu:\n";
  for (int i = 0; i < static_cast<int>(menu.size()); i++) {
    std::cout << i << " - " << menu[i] << " (" << prices[i] << ")\n";
  }
}

Automata::STATES Automata::getState() {
  return state;
}

void Automata::choice(int index) {
  if (state == ACCEPT && index >= 0 && index < static_cast<int>(menu.size())) {
    choiceIndex = index;
    state = CHECK;
    std::cout << "Selected: " << menu[index] << "\n";
  }
}

void Automata::check() {
  if (state == CHECK) {
    if (cash >= prices[choiceIndex]) {
      state = COOK;
      std::cout << "Enough money\n";
    } else {
      std::cout << "Not enough money\n";
      state = WAIT;
    }
  }
}

void Automata::cook() {
  if (state == COOK) {
    std::cout << "Cooking " << menu[choiceIndex] << "...\n";
    cash -= prices[choiceIndex];
    finish();
  }
}

void Automata::finish() {
  std::cout << "Ready! Change: " << cash << "\n";
  state = WAIT;
  choiceIndex = -1;
}

void Automata::cancel() {
  std::cout << "Cancelled. Refund: " << cash << "\n";
  cash = 0;
  state = WAIT;
}