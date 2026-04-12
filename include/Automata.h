#pragma once
#include <string>
#include <vector>
enum class STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
class Automata {
    int cash{};
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state = STATES::OFF;
    void loadMenu();
public:
    Automata();
    void on();
    void off();
    void coin(int sum);
    std::string etMenu() const;
    STATES getState() const;
    void choice(int idx);
    void check();
    void cancel();
    void cook();
    void finish();
};
