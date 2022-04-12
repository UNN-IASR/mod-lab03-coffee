#pragma once
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Automata
{
private:
	int cash;
	int selection;
	list<string> menu;
	list<int> prices;
	bool isChecked;

public:
	enum States {
		OFF, WAIT, ACCEPT, CHECK, COOK, FINISH
	};

	Automata();

	void on();
	void off();
	void coin(int);
	void getMenu();
	States getState();
	void choice(int);
	void check();
	void cancel();
	void cook();
	void finish();
};