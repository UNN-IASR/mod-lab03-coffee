#pragma once
#include <iostream>
using namespace std;

enum States {
		Off,
		Wait,
		Accept,
		Check,
		Cook
	};

class Automata
{

public:
	
	void on();
	void off();
	void coin(unsigned int sum);
	void GetMenu();
	States GetState();
	void choice(int num);
	void check(int num);
	void cancel();
	void cook(int num);
	void finish();
	Automata();

private:
	unsigned int cash;
	string* menu;
	unsigned int* prices;
	States state;

};
