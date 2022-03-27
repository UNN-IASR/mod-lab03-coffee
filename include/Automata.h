// Copyright 2022 UNN-IASR
#pragma once
#include <string>
using std::string;

enum STATES {
        OFF,
        WAIT,
        COOK,
        ACCEPT,
        CHECK
};

class Automata {
 private:
        int cash;
        string menu[4] = { "Coffee", "White tea", "Green tea", "Black tea" };
        int prices[4] = { 149, 119, 99, 129 };
        STATES state;
        int choice_user;

 public:
        Automata();
        void on();
        void off();
        void coin(int c);
        string* etMenu();
        STATES getState();
        void choice(int c);
        void check();
        int cancel();
        void cook();
        void finish();
};
