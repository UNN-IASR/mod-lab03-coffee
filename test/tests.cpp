// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"

// Тест 1
TEST(AutomataTest, InitialStateIsOff) {
    Automata a;
    EXPECT_EQ(a.getState(), STATES::OFF);
}

// Тест 2
TEST(AutomataTest, OnSwitchesToWait) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

// Тест 3
TEST(AutomataTest, OffFromWaitSwitchesToOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), STATES::OFF);
}

// Тест 4
TEST(AutomataTest, CoinSwitchesToAccept) {
    Automata a;
    a.on();
    a.coin(20);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

// Тест 5
TEST(AutomataTest, CoinAccumulatesCash) {
    Automata a;
    a.on();
    a.coin(20);
    a.coin(30);
    EXPECT_EQ(a.getCash(), 50);
}

// Тест 6
TEST(AutomataTest, CancelFromAcceptResetsToWait) {
    Automata a;
    a.on();
    a.coin(50);
    a.cancel();
    EXPECT_EQ(a.getState(), STATES::WAIT);
    EXPECT_EQ(a.getCash(), 0);
}

// Тест 7
TEST(AutomataTest, ChoiceSwitchesToCheck) {
    Automata a;
    a.on();
    a.coin(60);
    a.choice(0);
    EXPECT_EQ(a.getState(), STATES::CHECK);
}

// Тест 8
TEST(AutomataTest, CheckInsufficientFundsReturnsToAccept) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(0);  // Кофе = 50 руб.
    a.check();
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

// Тест 9
TEST(AutomataTest, FullSuccessfulPurchaseEndsInWait) {
    Automata a;
    a.on();
    a.coin(60);
    a.choice(0);  // Кофе = 50 руб.
    a.check();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

// Тест 10
TEST(AutomataTest, CashIsZeroAfterPurchase) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    a.check();
    EXPECT_EQ(a.getCash(), 0);
}

// Тест 11
TEST(AutomataTest, OnDoesNothingIfAlreadyWait) {
    Automata a;
    a.on();
    a.on();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

// Тест 12
TEST(AutomataTest, OffDoesNothingIfAlreadyOff) {
    Automata a;
    a.off();
    EXPECT_EQ(a.getState(), STATES::OFF);
}

// Тест 13
TEST(AutomataTest, CoinDoesNothingWhenOff) {
    Automata a;
    a.coin(50);
    EXPECT_EQ(a.getState(), STATES::OFF);
    EXPECT_EQ(a.getCash(), 0);
}

// Тест 14
TEST(AutomataTest, InvalidChoiceDoesNotChangeState) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(99);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

// Тест 15
TEST(AutomataTest, CancelFromWaitStaysWait) {
    Automata a;
    a.on();
    a.cancel();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}
