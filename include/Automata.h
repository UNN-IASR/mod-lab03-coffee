// Copyright 2024 GHA Test Team

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

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
    double cash;
    std::vector<std::string> menu;
    std::vector<double> prices;
    STATES state;
    int selectedDrink;  

 public:
    explicit Automata(const std::vector<std::string>& menuList,
                      const std::vector<double>& priceList);

    void on();
    void off();
    void coin(double amount);
    void cancel();
    void choice(int drinkIndex);
    void check();
    void cook();
    void finish();

    std::vector<std::string> getMenu() const;
    std::vector<double> getPrices() const;
    STATES getState() const;
    double getCash() const;
    int getSelectedDrink() const;
};

#endif  // INCLUDE_AUTOMATA_H_
