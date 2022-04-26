// Copyright 2022 UNN-IASR
#pragma once
#include <iostream>
#include <string>

using std::string;

class Automata{
 private:
    enum State
    {OFF, WAIT, ACCEPT, CHECK, COOK};

 public:
    int cash = 0; //текущая сумма
    string menu[2] = { "1" , "2"}; //названия напитков;
    int prices[2] = {100, 200}; //цены напитков;
    State state = OFF; //текущее состояние;
    int choice_p;
    void on(); //вкл;
    void off();//выкл;
    void coin(int m); //зачисление MONEY;
    string* etMenu(); // считывание меню;
    State getState() {return state;}//считывание текущего;
    void choice(int ch);//выбор напитка;
    void check();//проверка суммы;
    int cancel();//отмена обслуживания;
    void cook();//приготовление напитка;
    void finish(int f);//завершение обслуживания пользователя.
};
