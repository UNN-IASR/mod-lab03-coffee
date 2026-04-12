// Copyright 2024 UNN-IASR
#pragma once
#include <vector>
#include <string>

// Состояния автомата (согласно схеме)
enum class STATES {
    OFF,    // Выключено
    WAIT,   // Ожидание
    ACCEPT, // Прием денег
    CHECK,  // Проверка наличности
    COOK    // Приготовление
};

class Automata {
 private:
    int cash;                       // Текущий баланс
    std::vector<std::string> menu;  // Названия напитков
    std::vector<int> prices;        // Цены напитков
    STATES state;                   // Текущее состояние

 public:
    Automata();

    // Методы переходов
    void on();
    void off();
    void coin(int amount);
    void getMenu() const;
    STATES getState() const;
    void choice(int index);
    bool check(int index);
    void cancel();
    void cook(int index);
    void finish();
};
