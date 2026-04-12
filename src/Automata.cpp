// Copyright 2026 Your Name

#include "Automata.h"

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

Automata::Automata()
    : cash_(0),
      menu_({"Tea", "Coffee", "Milk"}),
      prices_({30, 50, 25}),
      state_(STATES::OFF),
      selected_index_(-1) {}

Automata::Automata(const std::vector<std::string>& menu,
                   const std::vector<int>& prices)
    : cash_(0),
      menu_(menu),
      prices_(prices),
      state_(STATES::OFF),
      selected_index_(-1) {
    if (menu_.size() != prices_.size()) {
        throw std::invalid_argument("Menu and prices size mismatch");
    }

    for (int price : prices_) {
        if (price < 0) {
            throw std::invalid_argument("Negative price");
        }
    }
}

void Automata::on() {
    if (state_ == STATES::OFF) {
        cash_ = 0;
        selected_index_ = -1;
        state_ = STATES::READY;
    }
}

void Automata::off() {
    cash_ = 0;
    selected_index_ = -1;
    state_ = STATES::OFF;
}

void Automata::coin(int amount) {
    if (state_ == STATES::OFF) {
        throw std::runtime_error("Machine is off");
    }

    if (amount <= 0) {
        throw std::invalid_argument("Amount must be positive");
    }

    cash_ += amount;
    state_ = STATES::WAIT_CHOICE;
}

std::string Automata::getMenu() const {
    std::ostringstream out;

    for (size_t i = 0; i < menu_.size(); ++i) {
        out << i << ". " << menu_[i] << " - "
            << prices_[i] << " rub.";
        if (i + 1 != menu_.size()) {
            out << '\n';
        }
    }

    return out.str();
}

STATES Automata::getState() const {
    return state_;
}

std::string Automata::choice(int index) {
    if (state_ == STATES::OFF) {
        throw std::runtime_error("Machine is off");
    }

    if (cash_ <= 0) {
        state_ = STATES::WAIT_MONEY;
        throw std::runtime_error("Insert money first");
    }

    if (index < 0 || index >= static_cast<int>(menu_.size())) {
        throw std::out_of_range("Invalid index");
    }

    selected_index_ = index;
    state_ = STATES::CHECKING;

    return menu_[index];
}

bool Automata::check() const {
    if (state_ != STATES::CHECKING) {
        throw std::runtime_error("Check not allowed");
    }

    return cash_ >= prices_[selected_index_];
}

std::string Automata::cook() {
    if (state_ != STATES::CHECKING) {
        throw std::runtime_error("Cannot cook now");
    }

    if (cash_ < prices_[selected_index_]) {
        throw std::runtime_error("Not enough money");
    }

    cash_ -= prices_[selected_index_];
    state_ = STATES::COOKING;

    return "Cooking " + menu_[selected_index_];
}

int Automata::cancel() {
    if (state_ == STATES::OFF) {
        throw std::runtime_error("Machine is off");
    }

    int refund = cash_;
    cash_ = 0;
    selected_index_ = -1;
    state_ = STATES::CANCELLED;

    return refund;
}

std::string Automata::finish() {
    if (state_ != STATES::COOKING &&
        state_ != STATES::CANCELLED) {
        throw std::runtime_error("Finish not allowed");
    }

    std::ostringstream out;

    if (state_ == STATES::COOKING) {
        out << "Drink ready";
        if (cash_ > 0) {
            out << ". Change: " << cash_ << " rub.";
        }
    } else {
        out << "Cancelled";
    }

    cash_ = 0;
    selected_index_ = -1;
    state_ = STATES::FINISHED;

    return out.str();
}

int Automata::getCash() const {
    return cash_;
}

int Automata::getSelectedIndex() const {
    return selected_index_;
}
