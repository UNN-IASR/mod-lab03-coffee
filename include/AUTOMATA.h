#ifndef Automata.h
#define AUTOMATA.h
#include <list>
#include <map>
#include <string>

enum states {Off, Wait, Accept, Check, Cook};

class Automata {
private: 
	int cash;
	std::map<std::string, int> prices;
	states state;
public: 
	Automata();
	~Automata();

	void on();
	void off();
	void coin(int money);
	void getMenu();
	states getState();
	void choice(std::string name);
	bool check(std::string name);
	void cancel();
	void cook(std::string name);
	void finish(std::string name);
};

#endif
