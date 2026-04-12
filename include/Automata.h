#pragma once
#include <vector>
#include <string>

enum class STATES {
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

public:
    Automata();

    void on();
    void off();
    void coin(int amount);
    void getMenu() const;
    STATES getState() const;
    void choice(int index);
    bool check(int index);
    void cancel();
    void cook(int index);
    void finish();
};