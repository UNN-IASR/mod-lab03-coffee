// Copyright 2026 EnganK

#include "Automata.h"
#include <sstream>
void Automata::loadMenu() {
    menu = { "tea", "coffee", "milk" };
    prices = { 30, 50, 40 };
}
Automata::Automata() { 
    loadMenu(); 
}
void Automata::on() {
    if (state == STATES::OFF)
    {
        cash = 0; state = STATES::WAIT;
    }
}
void Automata::off() {
    if (state == STATES::WAIT)
        state = STATES::OFF;
}
void Automata::coin(int sum) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) 
    {
        cash += sum;
        state = STATES::ACCEPT;
    }
}
std::string Automata::etMenu() const {
    std::ostringstream o;
    for (size_t i = 0; i < menu.size(); ++i)
        o << i << ") " << menu[i] << " " << prices[i] << "\n";
    return o.str();
}
STATES Automata::getState() const {
    return state;
}
void Automata::choice(int idx) {
    if (state == STATES::ACCEPT && idx >= 0 && idx < (int)menu.size())
        state = STATES::CHECK;
}
void Automata::check() {
    if (state != STATES::CHECK)
        return;
    int need = prices[0];
    state = cash >= need ? STATES::COOK : STATES::CHECK;
}
void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) 
    {
        cash = 0;
        state = STATES::WAIT;
    }
}
void Automata::cook() {
    if (state == STATES::CHECK)
        state = STATES::COOK;
}
void Automata::finish() {
    if (state == STATES::COOK)
    {
        cash = 0; state = STATES::WAIT;
    }
}
