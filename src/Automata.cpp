// Copyright 2024 GHA Test Team

#include <string>
#include <utility>
#include <vector>

#include "../include/Automata.h"

std::string stateToStr(STATES s) {
    switch (s) {
        case STATES::OFF:
            return "OFF";
        case STATES::WAIT:
            return "WAIT";
        case STATES::ACCEPT:
            return "ACCEPT";
        case STATES::CHECK:
            return "CHECK";
        case STATES::COOK:
            return "COOK";
        default:
            return "UNKNOWN";
    }
}

Automata::Automata(std::vector<std::string> menu,
                   std::vector<int> prices)
    : cash_(0), state_(STATES::OFF), selected_idx_(-1) {
    if (menu.empty()) {
        menu_ = {"Tea", "Coffee", "Juice", "Water"};
    } else {
        menu_ = std::move(menu);
    }

    if (prices.empty()) {
        prices_ = {50, 75, 60, 30};
    } else {
        prices_ = std::move(prices);
    }
}

bool Automata::on() {
    if (state_ == STATES::OFF) {
        state_ = STATES::WAIT;
        return true;
    }
    return false;
}

bool Automata::off() {
    if (state_ == STATES::WAIT || state_ == STATES::OFF) {
        state_ = STATES::OFF;
        cash_ = 0;
        selected_idx_ = -1;
        return true;
    }
    return false;
}

bool Automata::coin(int amount) {
    if (amount <= 0) {
        return false;
    }

    if (state_ == STATES::WAIT) {
        state_ = STATES::ACCEPT;
        cash_ += amount;
        return true;
    }

    if (state_ == STATES::ACCEPT) {
        cash_ += amount;
        return true;
    }

    return false;
}

std::vector<std::pair<std::string, int>> Automata::getMenu() const {
    std::vector<std::pair<std::string, int>> result;

    if (state_ == STATES::WAIT || state_ == STATES::ACCEPT ||
        state_ == STATES::CHECK) {
        for (size_t i = 0; i < menu_.size(); ++i) {
            result.emplace_back(menu_[i], prices_[i]);
        }
    }

    return result;
}

STATES Automata::getState() const {
    return state_;
}

bool Automata::choice(int index) {
    if (state_ == STATES::ACCEPT) {
        if (index >= 0 && index < static_cast<int>(menu_.size())) {
            selected_idx_ = index;
            state_ = STATES::CHECK;
            return true;
        }
    }

    return false;
}

bool Automata::check() const {
    if (state_ == STATES::CHECK) {
        return cash_ >= prices_[selected_idx_];
    }

    return false;
}

bool Automata::cancel() {
    if (state_ == STATES::ACCEPT || state_ == STATES::CHECK) {
        cash_ = 0;
        selected_idx_ = -1;
        state_ = STATES::WAIT;
        return true;
    }

    return false;
}

bool Automata::cook() {
    if (state_ == STATES::CHECK) {
        if (check()) {
            cash_ -= prices_[selected_idx_];
            state_ = STATES::COOK;
            return true;
        }
    }

    return false;
}

bool Automata::finish() {
    if (state_ == STATES::COOK) {
        selected_idx_ = -1;
        state_ = STATES::WAIT;
        return true;
    }

    return false;
}

int Automata::getCash() const {
    return cash_;
}
