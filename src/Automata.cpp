#include "Automata.h"

#include <sstream>
#include <stdexcept>

Automata::Automata()
    : cash(0),
      menu({"Tea", "Coffee", "Milk"}),
      prices({30, 50, 25}),
      state(STATES::OFF),
      selectedIndex(-1) {}

Automata::Automata(const std::vector<std::string>& menu_,
                   const std::vector<int>& prices_)
    : cash(0), menu(menu_), prices(prices_),
      state(STATES::OFF), selectedIndex(-1) {
    if (menu.size() != prices.size()) {
        throw std::invalid_argument("Menu and prices sizes must match");
    }

    for (int price : prices) {
        if (price < 0) {
            throw std::invalid_argument("Price must be non-negative");
        }
    }
}

void Automata::on() {
    if (state == STATES::OFF) {
        cash = 0;
        selectedIndex = -1;
        state = STATES::READY;
    }
}

void Automata::off() {
    cash = 0;
    selectedIndex = -1;
    state = STATES::OFF;
}

void Automata::coin(int amount) {
    if (state == STATES::OFF) {
        throw std::runtime_error("Machine is off");
    }

    if (amount <= 0) {
        throw std::invalid_argument("Amount must be positive");
    }

    cash += amount;
    state = STATES::WAIT_CHOICE;
}

std::string Automata::getMenu() const {
    std::ostringstream out;

    for (size_t i = 0; i < menu.size(); ++i) {
        out << i << ". " << menu[i] << " - " << prices[i] << " rub.";
        if (i + 1 != menu.size()) {
            out << '\n';
        }
    }

    return out.str();
}

STATES Automata::getState() const {
    return state;
}

std::string Automata::choice(int index) {
    if (state == STATES::OFF) {
        throw std::runtime_error("Machine is off");
    }

    if (cash <= 0) {
        state = STATES::WAIT_MONEY;
        throw std::runtime_error("Insert money first");
    }

    if (index < 0 || index >= static_cast<int>(menu.size())) {
        throw std::out_of_range("Invalid drink index");
    }

    selectedIndex = index;
    state = STATES::CHECKING;
    return menu[index];
}

bool Automata::check() const {
    if (state != STATES::CHECKING) {
        throw std::runtime_error("Check is not available now");
    }

    return cash >= prices[selectedIndex];
}

std::string Automata::cook() {
    if (state != STATES::CHECKING) {
        throw std::runtime_error("Cooking is not available now");
    }

    if (cash < prices[selectedIndex]) {
        throw std::runtime_error("Not enough money");
    }

    cash -= prices[selectedIndex];
    state = STATES::COOKING;

    return "Cooking " + menu[selectedIndex];
}

int Automata::cancel() {
    if (state == STATES::OFF) {
        throw std::runtime_error("Machine is off");
    }

    int refund = cash;
    cash = 0;
    selectedIndex = -1;
    state = STATES::CANCELLED;

    return refund;
}

std::string Automata::finish() {
    if (state != STATES::COOKING && state != STATES::CANCELLED) {
        throw std::runtime_error("Finish is not available now");
    }

    std::ostringstream out;

    if (state == STATES::COOKING) {
        out << "Drink is ready";
        if (cash > 0) {
            out << ". Change: " << cash << " rub.";
        } else {
            out << ". No change.";
        }
    } else {
        out << "Service cancelled";
    }

    cash = 0;
    selectedIndex = -1;
    state = STATES::FINISHED;

    return out.str();
}

int Automata::getCash() const {
    return cash;
}

int Automata::getSelectedIndex() const {
    return selectedIndex;
}
