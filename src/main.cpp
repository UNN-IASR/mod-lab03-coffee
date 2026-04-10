// Copyright 2024 GHA Test Team
 
#include <iostream>
#include <vector>
#include <string>
#include "Automata.h"
 
int main() {
   
    std::vector<std::string> menu = {"Кофе", "Чай", "Какао", "Молоко"};
    std::vector<double> prices    = {50.0,   30.0,  45.0,    25.0};
 
    Automata machine(menu, prices);
 
    std::cout << "=== Демонстрация работы автомата горячих напитков ===\n\n";
 
    
    std::cout << "-- Сценарий 1: Покупка кофе --\n";
    machine.on();
    machine.coin(30.0);
    machine.coin(30.0);   
    machine.choice(0);    
    machine.check();     
 
    std::cout << "\n";
 
   
    std::cout << "-- Сценарий 2: Чай, сначала мало денег --\n";
    machine.coin(10.0);  
    machine.choice(1);    
    machine.check();      
    machine.coin(20.0);   
    machine.choice(1);    
    machine.check();      
 
    std::cout << "\n";
 
   
    std::cout << "-- Сценарий 3: Отмена сеанса --\n";
    machine.coin(50.0);
    machine.cancel();    
 
    std::cout << "\n";
 
    
    std::cout << "-- Сценарий 4: Покупка молока (точная сумма) --\n";
    machine.coin(25.0);
    machine.choice(3);    
    machine.check();
 
    std::cout << "\n";
 
   
    std::cout << "-- Выключение автомата --\n";
    machine.off();
 
    return 0;
}
