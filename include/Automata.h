#ifndef AUTOMATA_H
#define AUTOMATA_H

#include<string>

const int MAX_DRINKS = 10;

enum STATES {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata {
private:
	int cash;
	std::string menu[MAX_DRINKS];
	int prices[MAX_DRINKS];
	int menuSize;
	STATES state;
	int chosenDrink;
	bool loadMenuFromFile(const std::string& filename);

public:
	Automata();
	Automata(const std::string& filename);
	void on();
	void off();
	void coin(int money);
	void getMenu();
	STATES getState();
	void choice(int drink);
	bool check();
	void cancel();
	void cook();
	void finish();
	int getCash();
	int getChosenDrink()const;
	int getMenuSize()const;
	int getPrice(int index)const;
};

#endif