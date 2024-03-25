#include <iostream>
#include "Automata.h"

int main() {
    Automata Machine;

    Machine.on();
    Machine.getMenu();
    Machine.coin(50);
    Machine.choice("cacao");

    Machine.off();
}
