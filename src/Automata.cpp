// Copyright 2022 UNN-IASR
#include "Automata.h"

Automata::Automata() {
  state = OFF;
  cash = 0;
  selection = -1;
  menu[0] = "Кофе";
  menu[1] = "Горячий кофе";
  menu[2] = "Очень горячий кофе";
  menu[3] = "Кофесодержащий продукт";
  prices[0] = 100;
  prices[1] = 110;
  prices[2] = 90;
  prices[3] = 250;
  isChecked = false;
}
void Automata::on() {
  state = WAIT;
}
void Automata::off() {
  state = OFF;
}
void Automata::coin(int sum) {
  cash += sum;
  state = ACCEPT;
}
void Automata::getMenu() {
  for (int i = 0; i < 4; i++)	{
    std::cout << menu[i] << " " << prices[i] << '\n';
  }
}
Automata::States Automata::getState() {
  return state;
}
void Automata::choice(int num) {
  selection = num;
  state = CHECK;
}
void Automata::check() {
  if (state != ACCEPT) {
    state = WAIT;
    return;
  }
  if (cash < prices[selection]) {
    state = WAIT;
  }
  else {
    isChecked = true;
  }
}
void Automata::cancel() {
  if (state != OFF) {
    isChecked = false;
    state = WAIT;
    cash = 0;
  }
}
void Automata::cook() {
  if (isChecked) {
    cash -= prices[selection];
    state == COOK;
  } else {
    state = WAIT;
  }
}
void Automata::finish() {
  if (state == COOK) {
    state = WAIT;
    cash = 0;
  }
}
