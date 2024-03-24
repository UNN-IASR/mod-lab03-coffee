// Copyright 2022 GHA Test Team

#pragma once
#include <iostream>
#include <string>

enum States {
Off,
Wait,
Accept,
Check,
Cook
};

class Automata{
 public:
void on();
void off();
void coin(unsigned int sum);
void GetMenu();
States GetState();
void choice(int num);
void check(int num);
void cancel();
void cook(int num);
void finish();
Automata();

 private:
unsigned int cash;
std::string* menu;
unsigned int* prices;
States state;
};
