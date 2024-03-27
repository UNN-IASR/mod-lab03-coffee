// Copyright 2024 Ekaterina Ryzhevskaya

#include <iostream>
#include "../include/Automata.h"

int main() {
	std::vector <std::string> states = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
	Automata a;

	a.on();
	std::cout << states[a.getState()] << std::endl;
	a.coin(50);
	a.coin(100);
	std::cout << a.getCash() << std::endl;
	std::cout << states[a.getState()] << std::endl;
	a.cancel();

	std::cout << states[a.getState()] << std::endl;
	a.coin(150);
	a.getMenu();
	a.choice(2);
	std::cout << states[a.getState()] << std::endl;
	std::cout << a.getCash() << std::endl;

	a.coin(50);
	a.choice(3);
	std::cout << states[a.getState()] << std::endl;
	a.coin(100);
	a.choice(3);
	std::cout << states[a.getState()] << std::endl;
}	