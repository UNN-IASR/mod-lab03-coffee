// Copyright 2024 UNN-IASR
#include <iostream>
#include "../include/Automata.h"

int main() {
    // Подключаем русский язык в консоли
    setlocale(LC_ALL, "Russian");

    Automata machine;

    std::cout << "=== Симуляция работы кофемашины ===" << std::endl;

    machine.on();
    machine.getMenu();

    machine.coin(50);
    machine.coin(60);

    int myChoice = 3;

    machine.choice(myChoice);
    machine.cook(myChoice);
    machine.finish();

    machine.off();

    return 0;
}