// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
#include <cassert>
#include <iostream>
#include <string>

void testInitialState() {
    Automata automata;
    assert(automata.getState() == State::OFF);
    assert(automata.getCash() == 0.0);
    std::cout << "✓ testInitialState passed" << std::endl;
}

void testOn() {
    Automata automata;
    automata.on();
    assert(automata.getState() == State::WAIT);
    std::cout << "✓ testOn passed" << std::endl;
}

void testOff() {
    Automata automata;
    automata.on();
    automata.off();
    assert(automata.getState() == State::OFF);
    std::cout << "✓ testOff passed" << std::endl;
}

void testCoin() {
    Automata automata;
    automata.on();
    automata.coin(100.0);
    assert(automata.getState() == State::ACCEPT);
    assert(automata.getCash() == 100.0);
    std::cout << "✓ testCoin passed" << std::endl;
}

void testMultipleCoins() {
    Automata automata;
    automata.on();
    automata.coin(50.0);
    automata.coin(30.0);
    automata.coin(20.0);
    assert(automata.getCash() == 100.0);
    std::cout << "✓ testMultipleCoins passed" << std::endl;
}

void testChoiceValid() {
    Automata automata;
    automata.on();
    automata.coin(100.0);
    bool result = automata.choice(1);
    assert(result == true);
    assert(automata.getState() == State::CHECK);
    std::cout << "✓ testChoiceValid passed" << std::endl;
}

void testChoiceInvalid() {
    Automata automata;
    automata.on();
    automata.coin(100.0);
    bool result = automata.choice(10);
    assert(result == false);
    assert(automata.getState() == State::ACCEPT);
    std::cout << "✓ testChoiceInvalid passed" << std::endl;
}

void testChoiceWithoutMoney() {
    Automata automata;
    automata.on();
    bool result = automata.choice(1);
    assert(result == false);
    assert(automata.getState() == State::WAIT);
    std::cout << "✓ testChoiceWithoutMoney passed" << std::endl;
}

void testCancelInAccept() {
    Automata automata;
    automata.on();
    automata.coin(100.0);
    automata.cancel();
    assert(automata.getState() == State::WAIT);
    assert(automata.getCash() == 0.0);
    std::cout << "✓ testCancelInAccept passed" << std::endl;
}

void testCancelInCheck() {
    Automata automata;
    automata.on();
    automata.coin(100.0);
    automata.choice(1);
    automata.cancel();
    assert(automata.getState() == State::WAIT);
    assert(automata.getCash() == 0.0);
    std::cout << "✓ testCancelInCheck passed" << std::endl;
}

void testCheckSufficientFunds() {
    Automata automata;
    automata.on();
    automata.coin(100.0);
    automata.choice(1);
    bool result = automata.check();
    assert(result == true);
    std::cout << "✓ testCheckSufficientFunds passed" << std::endl;
}

void testCheckInsufficientFunds() {
    Automata automata;
    automata.on();
    automata.coin(30.0);
    automata.choice(2);
    bool result = automata.check();
    assert(result == false);
    std::cout << "✓ testCheckInsufficientFunds passed" << std::endl;
}

void testFullPurchase() {
    Automata automata;
    automata.on();
    automata.coin(100.0);
    automata.choice(1);
    automata.cook();
    automata.finish();
    assert(automata.getState() == State::WAIT);
    assert(automata.getCash() == 0.0);
    std::cout << "✓ testFullPurchase passed" << std::endl;
}

void testGetMenuWhenOff() {
    Automata automata;
    std::string menu = automata.getMenu();
    assert(menu.find("выключен") != std::string::npos);
    std::cout << "✓ testGetMenuWhenOff passed" << std::endl;
}

void testGetMenuWhenOn() {
    Automata automata;
    automata.on();
    std::string menu = automata.getMenu();
    assert(menu.find("Чай") != std::string::npos);
    assert(menu.find("Кофе") != std::string::npos);
    std::cout << "✓ testGetMenuWhenOn passed" << std::endl;
}

void testInvalidCoinAmount() {
    Automata automata;
    automata.on();
    automata.coin(-10.0);
    assert(automata.getCash() == 0.0);
    automata.coin(0.0);
    assert(automata.getCash() == 0.0);
    std::cout << "✓ testInvalidCoinAmount passed" << std::endl;
}

void testGiveChange() {
    Automata automata;
    automata.on();
    automata.coin(150.0);
    automata.choice(3);
    automata.cook();
    automata.finish();
    assert(automata.getCash() == 0.0);
    std::cout << "✓ testGiveChange passed" << std::endl;
}

int main() {
    std::cout << "\nЗАПУСК тестов\n" << std::endl;
    testInitialState();
    testOn();
    testOff();
    testCoin();
    testMultipleCoins();
    testChoiceValid();
    testChoiceInvalid();
    testChoiceWithoutMoney();
    testCancelInAccept();
    testCancelInCheck();
    testCheckSufficientFunds();
    testCheckInsufficientFunds();
    testFullPurchase();
    testGetMenuWhenOff();
    testGetMenuWhenOn();
    testInvalidCoinAmount();
    testGiveChange();
    std::cout << "\nВСЕ ТЕСТЫ ПРОЙДЕНЫ!\n" << std::endl;
    return 0;
}
