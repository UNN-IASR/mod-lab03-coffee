// Copyright 2026 Belev Timur
#include "Automata.h"
#include <iostream>

int main() {
    std::cout << "=РАБОТА АВТОМАТА ГОРЯЧИХ НАПИТКОВ=\n" << std::endl;
    Automata automata;
    std::cout << "\n-Сценарий 1: Успешная покупка-\n" << std::endl;
    automata.on();
    std::cout << automata.getMenu();
    automata.coin(150.0);
    automata.choice(3);
    automata.cook();
    automata.finish();
    std::cout << "\n-Сценарий 2: Недостаточно средств-\n" << std::endl;
    automata.on();
    automata.coin(50.0);
    automata.choice(2);
    automata.cook();
    std::cout << "\n-Сценарий 3: Отмена операции-\n" << std::endl;
    automata.on();
    automata.coin(100.0);
    automata.cancel();
    std::cout << "\n4: Внесение доп средств-\n" << std::endl;
    automata.on();
    automata.coin(50.0);
    automata.coin(30.0);
    automata.choice(4);
    automata.coin(50.0);
    automata.choice(4);
    automata.cook();
    automata.finish();
    std::cout << "\n-Сценарий 5: Выключение автомата-\n" << std::endl;
    automata.off();
    std::cout << automata.getMenu();
    automata.on();
    automata.off();
    std::cout << "\n=ЗАВЕРШЕНИЕ=\n" << std::endl;
    return 0;
}
