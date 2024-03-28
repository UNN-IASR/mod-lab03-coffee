#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

struct MenuItem {
    float price;
    std::string name;
};

class Automata {
 private:
    enum States {
        OFF = 1,
        WAIT = 2,
        ACCEPT = 3,
        CHECK = 4,
        COOK = 5 
    };
    std::map<int, MenuItem> coffeMenuMap;
    States currentState;
    float currentCash;
    MenuItem item;

 public:
    Automata();

    void on();
    
    void off();
    
    void coin(float value);
    
    void choice(float value);
    
    bool check();
    
    void cancel();
    
    void cook();
    
    void finish();
    
    void getMenu();
    
    int getAutomataState();
    
    float getCurrentCash();
    
    MenuItem getChoice();
    
};
