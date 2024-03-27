// Copyright 2024 Nekkozzz

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

class Automata {
private:
    enum states {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };
    struct menu_item {
        std::string name;
        int price;
    };
    std::map<int, menu_item> menu;
    states state;
    float cash;
    menu_item item;
public:
    Automata();
    void on();
    void off();
    void coin(const float value);
    void choice(const int value);
    bool check();
    void cancel();
    void cook();
    void finish();

    void getMenu();
    int getState();
    float getCash();
    menu_item getChoice();
    void log(const std::string value);
};
