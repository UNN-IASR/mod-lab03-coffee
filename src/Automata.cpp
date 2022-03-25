// Copyright 2022 Dacyto

#include "Automata.h"

using std::cout;
using std::endl;

Automata::Automata() {
  state = OFF;
  cash = 0;
}

void Automata::on() {
  if (state == OFF) state = WAIT;
}

void Automata::off() {
  if (state == WAIT) state = OFF;
}

void Automata::coin(int c) {
  if (state == WAIT) state = ACCEPT;
  cash = cash + c;
}

STATES Automata::getState() {
  return state;
}

void Automata::getMenu() {
  for (int i = 0; i < 8; i++) {
    cout << menu[i] << "  " << prices[i] << " RUB" << endl;
  }
}

void Automata::choice(int x) {
  if (state == ACCEPT) {
    state = CHECK;
    variety = x -1;
  }
}

bool Automata::check() {
    if (state == CHECK && cash >= prices[variety]) return true;
    return false;
}

  void Automata::cook() {
    if (state == CHECK) {
      state = COOK;
      cash = cash - prices[variety];
    }
  }

int Automata::cancel() {
  int change = 0;
  if (state == ACCEPT || state == CHECK) {
    change = cash;
    state = WAIT;
    cash = 0;
  }
  return change; // возвращаем деньги после отмены операции приготовл. напитка
}

int Automata::finish() {
  int change = 0;
  if (state == COOK) {
    state = WAIT;
    change = cash;
    cash = 0;
  }
  return change; // возвращаем сдачу после приготовления напитка
}
