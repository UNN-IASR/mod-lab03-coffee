#pragma once
#include <vector>
#include <string>

using namespace std;

enum States {
	Off,
	Wait,
	Accept,
	Check,
	Cook,
};

class Automata {
private:
	int cash;
	States state;
	const vector<string> menu = { "Strawberry cocktail", "Chokolate cocktail", "Black tea", "Green tea", "Coffee" };
	const vector<int> prices = { 60, 70, 40, 45, 50 };
public:
	Automata();
	void on();
	void off();
	void coin(int money);
	vector<string> getMenu();
	States getState();
	int choice(string drink);
	bool check(int index);
	int cancel();
	void cook(int index);
	int finish();
};
