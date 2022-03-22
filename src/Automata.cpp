// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>

Automata::Automata() {
  cash = 0;
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

void Automata::coin(int c) {
  if (state == WAIT) {
    state = ACCEPT;
  }
  cash = cash + c;
}

string* Automata::etMenu() {
  return menu;
}

STATES Automata::getState() {
  return state;
}

void Automata::choice(int c) {
  if (state == ACCEPT) {
    state = CHECK;
    this->choice_user = c;
    check();
  }
}

void Automata::check() {
  if (state == CHECK) {
    if (cash - prices[choice_user - 1] >= 0)
      cook();
    else
       state = ACCEPT;
  }
}

int Automata::cancel() {
  if (state == ACCEPT || state == CHECK || state == WAIT) {
    state = WAIT;
    int c = cash;
    cash = 0;
    return c;
  } else {
      return 0;
  }
}

void Automata::cook() {
  if (state == CHECK) {
      state = COOK;
  }
}

void Automata::finish() {
  state = WAIT;
  cash = cash - prices[choice_user - 1];
  choice_user = -1;
}
