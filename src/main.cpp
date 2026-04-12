#include <iostream>
#include "../include/Automata.h"


int main(){
    Automata coffee;
    coffee.etMenu("testdata");
    std:: cout << coffee.menu[0];
    std::cout << coffee.prices[0];
    std::cout << coffee.menu[1];
    std::cout << coffee.prices[1];
}