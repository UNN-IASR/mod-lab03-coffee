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
std::map <int, std::string> menu;
std::map <int, int> prices;
int choice;
Automata() {
this->state = OFF;
this->cash = 0;
this->choice = -1;
menu[0] = "Горячий шоколад";
menu[1] = "Двойной шоколад";
menu[2] = "Какао";
menu[3] = "Холодный кофе";
menu[4] = "Горячий кофе";
menu[5] = "Холодный чай";
prices[0] = 200;
prices[1] = 300;
prices[2] = 100;
prices[3] = 180;
prices[4] = 150;
prices[5] = 500;
}
void on();
void off();
void coin(int);
void etMenu(std::map <int, std::string>, std::map <int, int>);
States getState();
int getCash();
void choiceuser(int);
void check();
void cancel();
void cook();
void finish();
};
