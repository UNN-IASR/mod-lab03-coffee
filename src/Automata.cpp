
#include "Automata.h"
#include <string>
#include <vector>


Automata::Automata() {
	state = state_off;
	cash = 0;
}

Automata::Automata(states st) {
	state = st;
	cash = 0;
}
void Automata::on() {
	if (state == state_off)
		state = state_on;
	else state = state;
}


states Automata::getState() {
	return state;
}
