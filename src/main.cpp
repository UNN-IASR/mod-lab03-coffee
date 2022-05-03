// Copyright 2020 GHA Test Team
#include <iostream>
#include <clocale>
#include "Automata.h"

int main() {
    setlocale(LC_ALL, "rus");
    Automata coffee{};
    std::cout << coffee.getMenu();
    std::cout << coffee.work("Latte", 17);
    return 0;
}
