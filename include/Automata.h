#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>
#include <vector>

enum class STATES {
    OFF,      
    ON,        
    WAIT,       
    ACCEPT,     
    CHECK,      
    COOK,       
    CANCEL,     
    FINISH     
};

class Automata {
private:
    double cash;                    
    std::vector<std::string> menu; 
    std::vector<double> prices;    
    STATES state;                 

public:
    Automata();

    void on();                      
    void off();                     
    void coin(double amount);       
    std::string getMenu();          
    STATES getState();             
    void choice(int drinkNumber);   
    bool check(int drinkNumber);    
    void cancel();                  
    void cook();                    
    void finish();                  

    double getCash() const;         
};

#endif