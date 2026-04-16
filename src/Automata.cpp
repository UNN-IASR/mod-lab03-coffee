// Copyright 2022 UNN-IASR
#include "Automata.h"

#include <chrono>
#include <iostream>
#include <stdexcept>
#include <thread>

Automata::Automata(std::ostream& os) : outStream{os} {
  menu.push_back(menuItem{"Espresso", 35});
  menu.push_back(menuItem{"Americano", 45});
  menu.push_back(menuItem{"Cappuccino", 50});
  menu.push_back(menuItem{"Hot chocolate", 65});
  menu.push_back(menuItem{"Raf", 120});
  menu.push_back(menuItem{"Tea", 20});
}

void Automata::on() {
  if (state == STATES::OFF) state = STATES::WAIT;
}

void Automata::off() {
  if (state != STATES::OFF) {
    state = STATES::OFF;
    cash = 0;
  }
}

void Automata::coin(double amount) {
  if (state == STATES::WAIT || state == STATES::ACCEPT) {
    if (amount <= 0) {
      throw std::runtime_error("invalid amount value");
    }
    state = STATES::ACCEPT;
    currentCash += amount;
  }
}

std::vector<menuItem> Automata::getMenu() {
  if (state != STATES::OFF) {
    for (menuItem item : menu) {
      outStream << item.itemName << ": " << item.itemPrice << "\n";
    }
    return menu;
  }
  return std::vector<menuItem>();
}

STATES Automata::getState() {
  switch (state) {
    case STATES::OFF:
      outStream << "OFF\n";
      break;
    case STATES::WAIT:
      outStream << "WAIT\n";
      break;
    case STATES::ACCEPT:
      outStream << "ACCEPT\n";
      break;
    case STATES::CHECK:
      outStream << "CHECK\n";
      break;
    case STATES::COOK:
      outStream << "COOK\n";
      break;
    default:
      outStream << "UNKNOWN\n";
      break;
  }
  return state;
}

double Automata::choice(size_t itemIndex) {
  if (state == STATES::ACCEPT) {
    if (itemIndex >= 0 && itemIndex < menu.size()) {
      state = STATES::CHECK;
      if (check(itemIndex)) {
        cash += menu[itemIndex].itemPrice;
        currentCash -= menu[itemIndex].itemPrice;
        double toReturn = currentCash;
        cook();
        outStream << "OK, change: " << toReturn << "\n";
        return toReturn;
      } else {
        double toReturn = cancel();
        outStream << "NOT ENOUGHT MONEY, change: " << toReturn << "\n";
        return toReturn;
      }
    } else {
      double toReturn = cancel();
      outStream << "INVALID ITEM, change: " << toReturn << "\n";
      return toReturn;
    }
  }
  outStream << "INACCESSIBLE, change: " << 0 << "\n";
  return 0;
}

double Automata::cancel() {
  if (state != STATES::OFF) {
    state = STATES::WAIT;
    double toReturn = currentCash;
    currentCash = 0;
    return toReturn;
  }
  return 0;
}

void Automata::cook() {
  if (state == STATES::CHECK) {
    state = STATES::COOK;
    outStream << "Start cooking\n";
    std::this_thread::sleep_for(std::chrono::seconds(10));
    finish();
  }
}

void Automata::finish() {
  if (state == STATES::COOK) {
    state = STATES::WAIT;
    currentCash = 0;
    outStream << "Finish\n";
  }
}

bool Automata::check(size_t drinkIndex) {
  if (state == STATES::CHECK) return currentCash >= menu[drinkIndex].itemPrice;
  return false;
}