// Copyright 2024 GHA Test Team
// Сценарий использования автомата горячих напитков

#include <iostream>
#include "Automata.h"

int main() {
    Automata a;

    std::cout << "=== Сценарий 1: Успешная покупка кофе ===\n";
    a.on();
    a.coin(30);
    a.coin(30);
    a.getMenu();
    a.choice(1);   // Кофе — 50 руб.
    std::cout << "\n";

    std::cout << "=== Сценарий 2: Недостаточно денег, доплата ===\n";
    a.coin(10);
    a.getMenu();
    a.choice(2);   // Чай — 30 руб., не хватает
    a.coin(20);    // доплата
    a.choice(2);   // Теперь хватает
    std::cout << "\n";

    std::cout << "=== Сценарий 3: Отмена покупки ===\n";
    a.coin(100);
    a.getMenu();
    a.cancel();
    std::cout << "\n";

    std::cout << "=== Сценарий 4: Выключение автомата ===\n";
    a.off();

    return 0;
}
