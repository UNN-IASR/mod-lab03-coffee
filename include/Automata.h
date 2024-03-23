// Copyright 2024 Danil Volkov

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <vector>
#include <string>

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;

    bool check(int);  // checking the availability of the required amount
    void cook(int);  // imitation of the beverage preparation process
    void finish(int);  // end of user service

 public:
    Automata();
    ~Automata();

    void on();  // turning on the machine
    void off();  // turning off the machine
    void coin(int);  // depositing money to the account by the user
    void getMenu();  // reading the menu with drinks and prices for the user
    STATES getState();  // reading the current status for the user
    void choice(int);  // the choice of a drink by the user
    void cancel();  // cancellation of a user service session
};


#endif  // INCLUDE_AUTOMATA_H_
