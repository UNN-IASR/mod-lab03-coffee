#include "../include/Automata.h"

int main() {
    Automata a;

    a.on();
    a.coin(2.0);
    a.choice(1);
    a.finish();
    a.off();

    return 0;
}
