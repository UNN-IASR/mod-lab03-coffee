#include <iostream>
#include "AUTOMATA.h"

int main() {
    Automata Machine;

    Machine.on();
    Machine.getMenu();
    Machine.coin(50);
    Machine.choice("cacao");

    Machine.off();
}
