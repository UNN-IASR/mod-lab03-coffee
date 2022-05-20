// Copyright 2022 UNN-IASR
#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

enum States {
OFF, ACCEPT, WAIT,
CHOSEN, MAKING, READY
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
menu[0] = "Макиато";
menu[1] = "Лунго";
menu[2] = "Бреве";
prices[0] = 150;
prices[1] = 160;
prices[2] = 170;
}
void on();
void off();
void coin();
void coin(int);
void etMenu(std::map <int, std::string>, std::map <int, int>);
void etMenu(std::string, std::string);
States getState();
int getCash();
void choiceuser();
void choiceuser(int);
void check();
void cancel();
void cook();
void finish();
};
