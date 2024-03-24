// Copyright 2024 Anna Chernyadeva

#include <iostream>
#include "Automata.h"

int main() {
    Automata CoffeeBreak;
    //Включаем автомат, покупаем напиток
    CoffeeBreak.on();
    CoffeeBreak.getMenu();
    CoffeeBreak.coin(30);
    CoffeeBreak.choice(3);
    std::cout << std::endl;

    //Докидываем нехватающие монеты
    CoffeeBreak.coin(1);
    CoffeeBreak.choice(4);
    CoffeeBreak.coin(39);
    CoffeeBreak.choice(4);
    std::cout << std::endl;

    //Отмена выбора
    std::cout << std::endl;
    CoffeeBreak.coin(100);
    CoffeeBreak.cancel();
    std::cout << CoffeeBreak.getState() << std::endl;


    CoffeeBreak.off();
}
