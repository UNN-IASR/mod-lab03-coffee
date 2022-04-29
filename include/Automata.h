// Copyright 2022 UNN-IASR
#pragma once
#include <iostream>
#include <string>

using std::string;

class Automata {
 private:
    enum State { OFF, WAIT, ACCEPT, CHECK, COOK };
    double amount = 0;
    string menu[2] = { "Tea" , "Coffee" };
    int prices[2] = { 100, 200 };
    State state = OFF;
    int selectedMenu;

 public:
    void On();
    void Off();
    void AddCoin(int cash);
    string* ReturnChoisenMenu();
    State GetState() { return state; }
    void ChoiceMenu(int ch);
    void Check();
    int Cancel();
    void Cook();
    void Finish(int f);
};
