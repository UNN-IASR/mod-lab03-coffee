#include <iostream>
#include "Automata.h"

void Work1(Automata automata)
{
	automata.on();

	automata.GetMenu();

	automata.coin(5);

	automata.choice(2);
	automata.check(2);

	automata.cancel();

	automata.coin(5);
	automata.coin(5);

	automata.choice(2);
	automata.check(2);

	automata.cook(2);

	automata.finish();

	automata.off();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Automata automata;
	Work1(automata);
	return 0;
}