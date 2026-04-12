// Copyright 2024 GHA Test Team

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <utility>
#include <vector>

enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

std::string stateToStr(STATES s);

class Automata {
 private:
    int cash_;
    std::vector<std::string> menu_;
    std::vector<int> prices_;
    STATES state_;
    int selected_idx_;

 public:
    explicit Automata(std::vector<std::string> menu = {},
                      std::vector<int> prices = {});

    bool on();
    bool off();
    bool coin(int amount);
    std::vector<std::pair<std::string, int>> getMenu() const;
    STATES getState() const;
    bool choice(int index);
    bool check() const;
    bool cancel();
    bool cook();
    bool finish();

    int getCash() const;
};
#endif  // INCLUDE_AUTOMATA_H_
