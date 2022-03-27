// Copyright 2022 UNN-IASR
#include <iostream>
#include "Automata.h"

using std::string;
using std::cout;

int main() {
    setlocale(LC_ALL, "Russian");
    Automata a;
    int b;
    a.on();
    cout << "Автомат готов принять заказ\n";
    getchar();
    a.coin(200);
    cout << "Деньги получены, пожалуйста сделайте выбор напитка\n";
    getchar();
    a.choice(1);
    cout << "Готовка...\n";
    getchar();
    a.finish();
    b = a.cancel();
    cout << "Ваша сдача " << b;
    getchar();
    a.off();
    cout << "\nВыключение автомата...\n";
}
