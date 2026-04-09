// Copyright 2026
#ifndef INCLUDE_AUTOMATA_H__
#define INCLUDE_AUTOMATA_H__

#include <string>
#include <vector>

enum class States {
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
    States state;
    int selected_item;

 public:
    Automata();
    void on();
    void off();
    void coin(int amount);
    std::string getMenu() const;          // изменено: теперь возвращает строку
    std::string getState() const;         // изменено: возвращает строку
    void choice(int index);               // изменено: void вместо bool
    bool check();
    void cancel();
    void cook();
    void finish();

    int getCash() const { return cash; }
    int getSelectedItem() const { return selected_item; }
};

#endif  // INCLUDE_AUTOMATA_H__