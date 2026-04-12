// Copyright 2026 Your Name

#include <gtest/gtest.h>

#include <stdexcept>
#include <string>
#include <vector>

#include "Automata.h"

TEST(AutomataTest, InitialState) {
    Automata a;
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, OnWorks) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), STATES::READY);
}

TEST(AutomataTest, CoinAddsMoney) {
    Automata a;
    a.on();
    a.coin(50);
    EXPECT_EQ(a.getCash(), 50);
}

TEST(AutomataTest, CoinWhenOffThrows) {
    Automata a;
    EXPECT_THROW(a.coin(10), std::runtime_error);
}

TEST(AutomataTest, ChoiceWithoutMoneyThrows) {
    Automata a;
    a.on();
    EXPECT_THROW(a.choice(0), std::runtime_error);
}

TEST(AutomataTest, InvalidChoiceThrows) {
    Automata a;
    a.on();
    a.coin(100);
    EXPECT_THROW(a.choice(10), std::out_of_range);
}

TEST(AutomataTest, CheckTrue) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);
    EXPECT_TRUE(a.check());
}

TEST(AutomataTest, CheckFalse) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(1);
    EXPECT_FALSE(a.check());
}

TEST(AutomataTest, CookWorks) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);
    a.cook();
    EXPECT_EQ(a.getState(), STATES::COOKING);
}

TEST(AutomataTest, FinishWorks) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), STATES::FINISHED);
}

TEST(AutomataTest, CancelWorks) {
    Automata a;
    a.on();
    a.coin(40);
    a.cancel();
    EXPECT_EQ(a.getCash(), 0);
}
