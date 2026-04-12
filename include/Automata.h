#pragma once

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>
#include <vector>

enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
private:
    STATES state;
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    int selectedItem;

public:

    Automata();

    void on();
    void off();
    void coin(int amount);
    std::string getMenu() const;
    STATES getState() const; 
    bool choice(int index);
    bool check();
    void cancel();
    void cook();
    void finish();


    int getCash() const;
    int getSelectedItem() const;
};

#endif
