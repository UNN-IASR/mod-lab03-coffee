// Copyright 2026
#include "Automata.h"
#include <iostream>

int main() {
    Automata machine;

    std::cout << "=== Демонстрация работы автомата ===\n\n";

    machine.on();
    std::cout << machine.getState() << std::endl;

    std::cout << machine.getMenu();

    machine.coin(20);
    std::cout << "Состояние: " << machine.getState() << std::endl;

    machine.coin(30);
    std::cout << "Баланс: " << machine.getCash() << " руб.\n";

    machine.choice(1);
    std::cout << "Состояние: " << machine.getState() << std::endl;

    if (machine.check()) {
        machine.cook();
        machine.finish();
    } else {
        std::cout << "Ошибка: недостаточно денег. Отмена.\n";
        machine.cancel();
    }

    std::cout << "\n--- Второй сеанс (недостаточно денег) ---\n";
    machine.coin(10);
    machine.choice(0);
    if (!machine.check()) {
        std::cout << "Не хватает, добавляем ещё монет...\n";
        machine.coin(30);
        machine.choice(0);
        if (machine.check()) {
            machine.cook();
            machine.finish();
        }
    }

    std::cout << "\n--- Отмена сеанса ---\n";
    machine.coin(100);
    machine.choice(2);
    machine.cancel();
    std::cout << "Состояние: " << machine.getState() << std::endl;

    std::cout << "\n--- Выключение автомата ---\n";
    machine.off();
    std::cout << machine.getState() << std::endl;

    return 0;
}