// Copyright 2022 UNN-IASR
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Automata.h"
void Automata::on() {
if (this->state == OFF) {
this->state = WAIT;
}
}
void Automata::off() {
this->state = OFF;
}
void Automata::coin(int money) {
if (this->state != OFF) {
this->cash += money;
this->state = ACCEPT;
}
}
void Automata::etMenu(std::map<int, std::string> menu,
std::map <int, int> prices) {
this->menu.clear();
this->prices.clear();
for (int i = 0; i < menu.size(); i++) {
this->menu[i] = menu[i];
}
for (int i = 0; i < prices.size(); i++)
this->prices[i] = prices[i];
if (this->prices.size() < this->menu.size()) {
for (int i = 0; i < this->menu.size() - this->prices.size(); i++) {
this->prices[this->prices.size()] = 50;
}
}
}
States Automata::getState() {
return this->state;
}
int Automata::getCash() {
return this->cash;
}
void Automata::choiceuser(int choice) {
if (this->state != OFF) {
this->choice = choice;
this->state = ACCEPT;
} else {
this->state = WAIT;
}
}
void Automata::check() {
if (this->state == ACCEPT) {
if (this->cash < this->prices[this->choice]) {
this->state = WAIT;
} else {
this->state = COOK;
}
} else {
this->state = WAIT;
}
}
void Automata::cancel() {
if (this->state != OFF) {
this->state = WAIT;
}
}
void Automata::cook() {
if (this->state == COOK) {
this->cash -= this->prices[this->choice];
this->state = WAIT;
}
}
void Automata::finish() {
this->state = WAIT;
}
