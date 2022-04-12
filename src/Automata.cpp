#include "Automata.h"

Automata::Automata() {
	States state = off;
	cash = 0;
	selection = -1;

	menu->add("Кофе");
	menu->add("Горячий кофе");
	menu->add("Очень горячий кофе");
	menu->add("Кофесодержащий продукт");

	prices->add(100);
	prices->add(110);
	prices->add(90);
	prices->add(250);

	isChecked = false
}
void Automata::on() {
	state = wait;
}
void Automata::off() {
	state = OFF;
}
void Automata::coin(int sum) {
	cash += sum;
	state = ACCEPT;
}
void Automata::getMenu() {
	for (int i = 0; i < menu.size(); i++)
	{
		cout << menu[i] << " " << prices[i] << '\n';
	}
}
States Automata::getState() {
	return state();
}
void Automata::choice(int num) {
	selection = num;
	state = CHECK;
}
void Automata::check() {
	if (state != ACCEPT) {
		state = WAIT;
		return;
	}
	if (cash < prices[selection]) {
		state = WAIT;
	}
	else {
		isChecked = true;
	}
}
void Automata::cancel() {
	if (state != OFF) {
		isChecked = false;
		state = WAIT;
		cash = 0;
	}
}

void Automata::cook() {
	if (isChecked) {
		cash -= prices[selection];
		state == COOK
	}
	else {
		state = WAIT;
	}
}

void Automata::finish() {
	if (state == COOK) {
		state = WAIT;
		cash = 0;
	}
}
