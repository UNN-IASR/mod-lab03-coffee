// Copyright 2022 GHA Test Team

#include "Automata.h"
#include <iostream>
#include <string>

Automata::Automata() {
  cash = 0;
  menu = { "Tea", "Coffee", "Kakao", "Hot chocolate" };
  prices = { 25, 55, 70, 60 };
  state = OFF;
  indexSelectedDrink = -1;
}

void Automata::on() {
  if (state == OFF) {
    state = WAIT;
    std::cout << "Automata is on and wait\n";
  } else {
    std::cout << "Automata can't switch to this state\n";
  }
}

void Automata::off() {
  if (state == WAIT) {
    state = OFF;
    std::cout << "Automata is off\n";
  } else if (state != OFF) {
    std::cout << "Automata can't switch to this state\n";
  }
}

void Automata::coin(unsigned int money) {
  if (state == WAIT || state == ACCEPT) {
    cash += money;
    state = ACCEPT;
    std::cout << "Put " << money << " coins\n";
    std::cout << "Total " << cash << " coins\n";
  } else if (state != OFF) {
    std::cout << "Automata can't switch to this state\n";
  }
}

void Automata::getMenu() {
  if (state != OFF) {
    std::cout << "Menu:\n";
    for (unsigned int i = 0; i < menu.size(); i++) {
      std::cout << i + 1 << ") " << menu[i]
        << ": " << prices[i] << std::endl;
    }
  }
}

std::string Automata::getState() {
  if (state == WAIT)
    return "WAIT";
  else if (state == ACCEPT)
    return "ACCEPT";
  else if (state == CHECK)
    return "CHECK";
  else if (state == COOK)
    return "COOK";
  else
    return "OFF";
}

void Automata::choice(unsigned int numberDrink) {
  if (state == ACCEPT) {
    if (numberDrink > menu.size() || numberDrink <= 0) {
      std::cout << "This number is not on the menu\n";
      return;
    }
    state = CHECK;
    indexSelectedDrink = numberDrink - 1;
    std::cout << menu[indexSelectedDrink] << " is selected\n";
  } else if (state != OFF) {
    std::cout << "Automata can't switch to this state\n";
  }
}

bool Automata::check() {
  if (state == CHECK) {
    if (cash >= prices[indexSelectedDrink]) {
      std::cout << "Enough coins, cooking begins\n";
      return true;
    } else {
      return false;
    }
  } else if (state != OFF) {
    std::cout << "Automata can't switch to this state\n";
    return false;
  } else {
    return false;
  }
}

void Automata::cancel() {
  if (state == ACCEPT || state == CHECK) {
    if (cash > 0) {
      std::cout << "Refund of money: " << cash << std::endl;
      cash = 0;
    }
    indexSelectedDrink = -1;
    state = WAIT;
  } else if (state != OFF) {
    std::cout << "Automata can't switch to this state\n";
  }
}

void Automata::cook() {
  if (state == CHECK && check()) {
    state = COOK;
    cash -= prices[indexSelectedDrink];
    std::cout << "Cooking " << menu[indexSelectedDrink]
        << "\n.\n" << "..\n" << "...\n" << "Done\n";
    finish();
  } else if (state != OFF) {
    std::cout << "Automata can't switch to this state\n";
  }
}

void Automata::finish() {
  if (state == COOK) {
    if (cash > 0) {
      std::cout << "Refund of money: " << cash << std::endl;
      cash = 0;
    }
    indexSelectedDrink = -1;
    state = WAIT;
  } else if (state != OFF) {
    std::cout << "Automata can't switch to this state\n";
  }
}

int Automata::getCash() const {
  return cash;
}

unsigned int Automata::getNumberSelectedDrink() const {
  return indexSelectedDrink + 1;
}
