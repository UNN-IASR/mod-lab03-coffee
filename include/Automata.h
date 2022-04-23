// Copyright 2022 UNN-IASR
#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
enum States {
OFF, ACCEPT, WAIT, CHECK, COOK
};

class Automata {
 public:
States state;
int cash;
std::map <int, int> prices;
std::map <int, std::string> menu;
int choice;
Automata() {
this->cash = 0;
this->choice = -1;
this->state = OFF;
menu[0] = "Горячий шоколад";
menu[1] = "Двойной шоколад";
menu[2] = "Какао";
prices[0] = 200;
prices[1] = 300;
prices[2] = 100;
}
void on();
void off();
void coin(int);
void etMenu(std::map <int, std::string>, std::map <int, int>);
int getCash();
void choiceuser(int);
void check();
void cancel();
void cook();
void finish();
States getState();
};
