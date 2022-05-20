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
void Automata::coin() {
if (this->state != OFF) {
int money = 0;
std::cout << "Введите сумму: ";
std::cin >> money;
this->coin(money);
}
}
void Automata::coin(int money) {
if (this->state != OFF) {
if (money < 0)
this->cash += -money;
else
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
void Automata::etMenu(std::string pathmenu, std::string pathprices) {
std::ifstream fin;
fin.open(pathmenu);
this->menu.clear();
this->prices.clear();
if (!fin.is_open()) {
std::cout << "Ошибка открытия файла\n";
} else {
while (!fin.eof()) {
std::getline(fin, this->menu[this->menu.size()]);
}
}
fin.close();
fin.open(pathprices);
if (!fin.is_open()) {
std::cout << "Ошибка открытия файла\n";
} else {
while (!fin.eof()) {
std::getline(fin, this->menu[this->menu.size()]);
this->prices[this->prices.size()] = std::stoi(this->menu[this->menu.size()-1]);
this->menu.erase(this->menu.size());
}
}
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
void Automata::choiceuser() {
int choice = 0;
std::cin >> choice;
this->choiceuser(choice);
}
void Automata::choiceuser(int choice) {
if (this->state == ACCEPT) {
if (choice<0 || choice>this->menu.size()) {
this->state = WAIT;
} else {
this->choice = choice;
this->state = CHOSEN;
}
}
}
void Automata::check() {
if (this->state == CHOSEN) {
if (this->cash < this->prices[this->choice]) {
this->state = WAIT;
} else {
this->state = MAKING;
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
if (this->state == MAKING) {
this->cash -= this->prices[this->choice];
this->state = READY;
}
}
void Automata::finish() {
this->state = WAIT;
}
