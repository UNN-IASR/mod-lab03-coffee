// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialStateIsOff) {
    Automata a;
    EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, OnSwitchesToWait) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, OffFromWaitSwitchesToOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, CoinFromWaitSwitchesToAccept) {
    Automata a;
    a.on();
    a.coin(50);
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(AutomataTest, MultipleCoinsSumCorrectly) {
    Automata a;
    a.on();
    a.coin(20);
    a.coin(30);
    EXPECT_EQ(a.cash, 50);
}

TEST(AutomataTest, ChoiceSwitchesToCheck) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);
    EXPECT_EQ(a.getState(), CHECK);
}

TEST(AutomataTest, CheckReturnsTrueWhenEnoughCash) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);  // Кофе — 50 руб.
    EXPECT_TRUE(a.check());
}

TEST(AutomataTest, CheckReturnsFalseWhenNotEnoughCash) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(0);  // Кофе — 50 руб.
    EXPECT_FALSE(a.check());
}

TEST(AutomataTest, CheckWithNotEnoughCashKeepsCheckState) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(0);
    a.check();
    EXPECT_EQ(a.getState(), CHECK);
}

TEST(AutomataTest, CookSwitchesToCook) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);
    a.cook();
    EXPECT_EQ(a.getState(), COOK);
}

TEST(AutomataTest, FinishSwitchesToWait) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, FinishDeductsPriceFromCash) {
    Automata a;
    a.on();
    a.coin(70);
    a.choice(0);  // Кофе — 50 руб.
    a.cook();
    a.finish();
    EXPECT_EQ(a.cash, 20);
}

TEST(AutomataTest, CancelFromAcceptSwitchesToWait) {
    Automata a;
    a.on();
    a.coin(30);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, CancelResetsCashToZero) {
    Automata a;
    a.on();
    a.coin(30);
    a.cancel();
    EXPECT_EQ(a.cash, 0);
}

TEST(AutomataTest, CancelFromCheckSwitchesToWait) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(0);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, OffDoesNotWorkFromAccept) {
    Automata a;
    a.on();
    a.coin(50);
    a.off();
    EXPECT_EQ(a.getState(), ACCEPT);
}
