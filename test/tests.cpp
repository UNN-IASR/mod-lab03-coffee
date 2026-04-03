// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
#include "Automata.h"
#include <cassert>

void testOnOff() {
    Automata a;
    a.on();
    assert(a.getState() == STATES::ON);
    a.off();
    assert(a.getState() == STATES::OFF);
    std::cout << "testOnOff passed\n";
}

void testCoinInsertion() {
    Automata a;
    a.on();
    a.coin(50.0);
    assert(a.getState() == STATES::ACCEPT);
    assert(a.getCash() == 50.0);
    std::cout << "testCoinInsertion passed\n";
}

void testMenu() {
    Automata a;
    std::string menu = a.getMenu();
    assert(menu.find("Tea") != std::string::npos);
    assert(menu.find("Coffee") != std::string::npos);
    std::cout << "testMenu passed\n";
}

void testChoiceInsufficientFunds() {
    Automata a;
    a.on();
    a.coin(30.0);
    a.choice(2); // Coffee costs 80
    assert(a.getState() == STATES::WAIT); 
    std::cout << "testChoiceInsufficientFunds passed\n";
}

void testCancel() {
    Automata a;
    a.on();
    a.coin(100.0);
    a.cancel();
    assert(a.getCash() == 0.0);
    assert(a.getState() == STATES::ON);
    std::cout << "testCancel passed\n";
}

void testFullPurchase() {
    Automata a;
    a.on();
    a.coin(80.0);
    a.choice(2); 
    assert(a.getState() == STATES::COOK);
    a.cook();
    assert(a.getState() == STATES::FINISH);
    a.finish();
    assert(a.getCash() == 0.0);
    assert(a.getState() == STATES::ON);
    std::cout << "testFullPurchase passed\n";
}

void testOffDuringPurchase() {
    Automata a;
    a.on();
    a.coin(50.0);
    a.off();
    assert(a.getCash() == 0.0);
    assert(a.getState() == STATES::OFF);
    std::cout << "testOffDuringPurchase passed\n";
}

void testCheckMethod() {
    Automata a;
    a.on();
    a.coin(100.0);
    bool canBuy = a.check(1); 
    assert(canBuy == true);
    a.cancel();
    a.coin(50.0);
    canBuy = a.check(1);
    assert(canBuy == false);
    std::cout << "testCheckMethod passed\n";
}

void testMultipleCoins() {
    Automata a;
    a.on();
    a.coin(30.0);
    a.coin(20.0);
    a.coin(30.0);
    assert(a.getCash() == 80.0);
    std::cout << "testMultipleCoins passed\n";
}

void testInvalidChoice() {
    Automata a;
    a.on();
    a.coin(100.0);
    a.choice(10); 
    assert(a.getState() == STATES::ACCEPT); 
    std::cout << "testInvalidChoice passed\n";
}

int main() {
    testOnOff();
    testCoinInsertion();
    testMenu();
    testChoiceInsufficientFunds();
    testCancel();
    testFullPurchase();
    testOffDuringPurchase();
    testCheckMethod();
    testMultipleCoins();
    testInvalidChoice();

    std::cout << "\nAll tests passed successfully!\n";
    return 0;
}