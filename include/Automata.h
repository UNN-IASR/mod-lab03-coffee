// Copyright 2022 UNN-IASR

#pragma once
#include <iostream>
#include <string>

enum STATES { COOK, CHECK, ACCEPT, WAIT, OFF };

class Automata {
 public:
    void on(); // включение автомата;
    void off(); // выключение автомата;
    void coin(int coins); // занесение денег на счёт пользователем;
    void getMenu(); // считывание меню с напитками и ценами для пользователя;
    STATES getState(); // считывание текущего состояния для пользователя;
    void choice(int drinkNumber); // выбор напитка пользователем;
    void check(int drinkNumber); // проверка наличия необходимой суммы;
    void cancel(); // отмена сеанса обслуживания пользователем;
    void cook(); // имитация процесса приготовления напитка;
    void finish(); // завершение обслуживания пользователя.
    Automata(std::string* menu, int* prices); //конструктор

 private:
    double cash; // для хранения текущей суммы;
    std::string menu[5]; // массив строк названий напитков;
    int prices[5]; // массив цен напитков;
    STATES state; // текущее состояние автомата;
};
