// Copyright 2022 GHA Test Team

#include "Automata.h"

Automata::Automata() {
cash = 0;
menu = new std::string[3]{"Чай", "Кофе", "Молоко"};
prices = new unsigned int[3]{5, 15, 8};
state = Off;
}

void Automata::on() {
if (state == Off) {state = Wait;
std::cout << "Автомат включился." << std::endl;}
else
std::cout << "Автомат уже включён." << std::endl;
}

void Automata::off() {
if (state == Wait) { state = Off;
std::cout << "Автомат выключился." << std::endl;}
else
if (state == Off)
std::cout << "Автомат уже выключён." << std::endl;
else
std::cout << "Автомат не завершил свою работу." << std::endl;
}
void Automata::coin(unsigned int sum) {
if (state == Wait || state == Accept) { state = Accept;
cash += sum; std::cout << "Деньги внесены: "<< sum << std::endl; }
else
std::cout << "Дождитесь завершения работы автомата." << std::endl;
}
void Automata::GetMenu() {
std::cout << " Меню:--------------------------------------- " << std::endl;
for (int i = 0; i < 3; i++) {
std::cout << menu[i] << " - " << prices[i] << std::endl; }
std::cout << " ---------------------------------------V0.1- " << std::endl;
}
States Automata::GetState() {
return state;
}
void Automata::choice(int num) {
if (state == Accept) {state = Check;
std::cout << "Выбор сделан: " << num << std::endl;}
else
std::cout << "Внесите деньги и выберите напиток." << std::endl;
}
void Automata::check(int num) {
if (state == Check) {
if (prices[num-1] <= cash) { state = Check;
std::cout << "Все деньги успешно внесены." << std::endl;
} else {
std::cout << "Недостаточно денег на счете, внесите до нужной суммы." <<
" ( " << cash << "из" << prices[num-1] << " )"<< std::endl;
}
} else {
std::cout << "Внесите деньги и выберите напиток." << std::endl;
}
}
void Automata::cancel() {
if (state == Accept || state ==Check) {state = Wait;
std::cout << "Операция прервана." << std::endl;
} else {
std::cout << "Дождитесь завершения работы автомата." << std::endl;
}
}
void Automata::cook(int num) {
if (state == Check && cash >= prices[num-1]) { state = Cook;
std::cout << "Приготовление напитка..." << menu[num-1]
<< std::endl; cash -= prices[num-1];
} else {
std::cout << "Внесите деньги и выберите напиток." << std::endl;
}
}
void Automata::finish() {
if (state == Cook) { state = Wait;
std::cout << "Напиток готов. Приятного аппетита." << std::endl;
} else {
std::cout << "Дождитесь завершения работы автомата." << std::endl;
}
}
