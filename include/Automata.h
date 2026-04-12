#pragma once
#include <vector>
#include <string>

using namespace std;

enum STATES {
    OFF,
    WAITING_FOR_COIN,
    WAITING_FOR_CHOICE,
    COOKING,
    FINISHED
};

class Automata {
private:
    double cash;
    vector<string> menu;
    vector<double> prices;
    STATES state;

public:
    Automata();

    void on();
    void off();

    void coin(double amount);

    string getMenu();
    STATES getState();

    void choice(int index);
    bool check(int index);

    void cook();
    void finish();

    void cancel();

    double getCash();
};
