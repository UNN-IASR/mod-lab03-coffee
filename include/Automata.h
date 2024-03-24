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
	//States CurrentState{ get; set; };
	Automata();

private:
	unsigned int cash;
	string* menu;
	unsigned int* prices;
	States state;
	
	
	/*on() - включение автомата;
	off() - выключение автомата;
	coin() - занесение денег на счёт пользователем;
	etMenu() - считывание меню с напитками и ценами для пользователя;
	getState() - считывание текущего состояния для пользователя;
	choice() - выбор напитка пользователем;
	check() - проверка наличия необходимой суммы;
	cancel() - отмена сеанса обслуживания пользователем;
	cook() - имитация процесса приготовления напитка;
	finish() - завершение обслуживания пользователя.*/

};