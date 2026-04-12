#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

enum class STATES {
    OFF,
    READY,
    WAIT_MONEY,
    WAIT_CHOICE,
    CHECKING,
    COOKING,
    FINISHED,
    CANCELLED
};

class Automata {
 private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
    int selectedIndex;

 public:
    Automata();
    Automata(const std::vector<std::string>& menu,
             const std::vector<int>& prices);

    void on();
    void off();

    void coin(int amount);

    std::string getMenu() const;
    STATES getState() const;

    std::string choice(int index);
    bool check() const;

    std::string cook();
    int cancel();
    std::string finish();

    int getCash() const;
    int getSelectedIndex() const;
};

#endif  
