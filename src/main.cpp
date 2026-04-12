// Copyright 2022 GHA Test Team
#include <iostream>
#include "Automata.h"

int main() {
    Automata a;

    std::cout << "=== Сценарий 1: Успешная покупка кофе ===\n";
    a.on();
    a.getMenu();
    a.coin(30);
    a.coin(30);
    a.choice(0);  // Кофе = 50 руб.
    a.check();

    std::cout << "\n=== Сценарий 2: Отмена после внесения денег ===\n";
    a.coin(50);
    a.cancel();

    std::cout << "\n=== Сценарий 3: Недостаточно средств, доп. внос ===\n";
    a.coin(20);
    a.choice(1);  // Чай = 30 руб.
    a.check();    // не хватает 10 руб.
    a.coin(10);
    a.choice(1);
    a.check();

    std::cout << "\n=== Сценарий 4: Выключение автомата ===\n";
    a.off();

    return 0;
}
