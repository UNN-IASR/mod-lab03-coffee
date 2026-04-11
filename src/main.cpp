#include "Automata.h"

int main() {
    Automata a;
    a.on();
    a.getMenu();
    a.coin(70);
    a.choice(1);
    a.check();
    a.coin(30);
    a.choice(1); 
    a.check();
    a.cook();

    return 0;
}