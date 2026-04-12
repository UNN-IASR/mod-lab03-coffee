// Copyright 2026 HirGior
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
     private:
        int cash;
        std::vector<std::string> menu;
        std::vector<int> prices;
        STATES state;
        int selectedIndex;

     public:
        Automata();

        void on();
        void off();
        void coin(int amount);
        void getMenu();
        STATES getState();
        void choice(int index);
        void check();
        void cancel();
        void cook();
        void finish();
};

#endif  // INCLUDE_AUTOMATA_H_
