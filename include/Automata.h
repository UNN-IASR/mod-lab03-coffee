#ifndef AUTOMATA_H_
#define AUTOMATA_H_
#include <string>
#include <vector>

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
	std::vector<std::string> menu;
	std::vector<int> prices;
	STATES state;
	int selectedDrink;
public:
	Automata();
	void on();
	void off();
	void coin(int money);
	std::string getMenu();
	STATES getState();
	void choice(int numDrink);
	bool check();
	void cancel();
	void cook();
	void finish();

	int getCash() const { return cash; }
	int getSelectedDrink() const { return selectedDrink; }
};
#endif // !AUTOMATA_H_
