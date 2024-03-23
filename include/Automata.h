// Copyright 2024 alenkaLo
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum states {
    state_on, state_off, state_cook, state_wait, 
    state_accept, state_check, state_error, state_finish
};

class Automata {
    private:
        int cash;
        std::vector <std::string> menu;
        std::vector <int> prices;
        states state;   

    public:
        explicit Automata();
        explicit Automata(states);
        void on();
        void off();
        void coin(int);
        void setMenu(const string);
        states getState();
        bool choice(string);
        bool check(const string);
        void cancel();
        void cook();
        void finish();
};
#endif  // INCLUDE_AUTOMATA_H_
