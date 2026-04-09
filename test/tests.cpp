// Copyright 2026

#include <gtest/gtest.h>
#include "Automata.h"
#include <cassert>
#include <iostream>
void test_initial_state() {
    Automata a;
    assert(a.getState() == "OFF (Выключен)");
    assert(a.getCash() == 0);
    std::cout << "test_initial_state passed\n";
}

void test_on() {
    Automata a;
    a.on();
    assert(a.getState() == "WAIT (Ожидание)");
    assert(a.getCash() == 0);
    std::cout << "test_on passed\n";
}

void test_off() {
    Automata a;
    a.on();
    a.off();
    assert(a.getState() == "OFF (Выключен)");
    a.off();
    assert(a.getState() == "OFF (Выключен)");
    std::cout << "test_off passed\n";
}

void test_coin_from_wait() {
    Automata a;
    a.on();
    a.coin(50);
    assert(a.getState() == "ACCEPT (Приём денег)");
    assert(a.getCash() == 50);
    std::cout << "test_coin_from_wait passed\n";
}

void test_coin_from_accept() {
    Automata a;
    a.on();
    a.coin(30);
    a.coin(20);
    assert(a.getCash() == 50);
    assert(a.getState() == "ACCEPT (Приём денег)");
    std::cout << "test_coin_from_accept passed\n";
}

void test_choice() {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(0);
    assert(a.getState() == "CHECK (Проверка средств)");
    assert(a.getSelectedItem() == 0);
    std::cout << "test_choice passed\n";
}

void test_check_sufficient() {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    bool res = a.check();
    assert(res == true);
    assert(a.getState() == "COOK (Приготовление)");
    std::cout << "test_check_sufficient passed\n";
}

void test_check_insufficient() {
    Automata a;
    a.on();
    a.coin(30);
    a.choice(1);
    bool res = a.check();
    assert(res == false);
    assert(a.getState() == "ACCEPT (Приём денег)");
    assert(a.getCash() == 30);
    std::cout << "test_check_insufficient passed\n";
}

void test_cancel() {
    Automata a;
    a.on();
    a.coin(70);
    a.choice(2);
    a.cancel();
    assert(a.getState() == "WAIT (Ожидание)");
    assert(a.getCash() == 0);
    assert(a.getSelectedItem() == -1);
    std::cout << "test_cancel passed\n";
}

void test_full_flow() {
    Automata a;
    a.on();
    a.coin(40);
    a.choice(3);
    assert(a.check() == true);
    a.cook();
    a.finish();
    assert(a.getState() == "WAIT (Ожидание)");
    assert(a.getCash() == 0);
    assert(a.getSelectedItem() == -1);
    std::cout << "test_full_flow passed\n";
}

void test_cancel_when_wait() {
    Automata a;
    a.on();
    a.cancel();
    assert(a.getState() == "WAIT (Ожидание)");
    std::cout << "test_cancel_when_wait passed\n";
}

void test_invalid_choice() {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(10);
    assert(a.getState() == "ACCEPT (Приём денег)");
    assert(a.getSelectedItem() == -1);
    std::cout << "test_invalid_choice passed\n";
}

int main() {
    std::cout << "Running tests...\n";
    test_initial_state();
    test_on();
    test_off();
    test_coin_from_wait();
    test_coin_from_accept();
    test_choice();
    test_check_sufficient();
    test_check_insufficient();
    test_cancel();
    test_full_flow();
    test_cancel_when_wait();
    test_invalid_choice();
    std::cout << "All tests passed!\n";
    return 0;
}