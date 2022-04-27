#include <stdio.h>
#include <iostream>
#include <string>

#ifndef MOD_LAB03_COFFEE_AUTOMATA_H
#define MOD_LAB03_COFFEE_AUTOMATA_H
#define MENU_ITEMS_COUNT 5

class Automata {
private:
    int cash;
    int selectedItem;
    std::string menu[MENU_ITEMS_COUNT];
    int prices[MENU_ITEMS_COUNT];
    bool isChecked;

public:
    enum States {
        OFF, WAIT, ACCEPT, CHECK, COOK, FINISH
    };

    States state;

    Automata();

    void on();

    void off();

    void coin(int);

    void getMenu();

    States getState();

    void choice(int);

    bool check();

    void cancel();

    void cook();

    void finish();

private:
    void initMenu();
};

#endif //MOD_LAB03_COFFEE_AUTOMATA_H
