// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialStateIsOff) {
    Automata a;
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, TurnOn) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, TurnOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, CoinChangesStateToAccept) {
    Automata a;
    a.on();
    a.coin(10.0);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

TEST(AutomataTest, CoinAccepted) {
    Automata a;
    a.on();
    a.coin(10.0);
    EXPECT_EQ(a.cash, 10.0);
}

TEST(AutomataTest, MultipleCoinsSummed) {
    Automata a;
    a.on();
    a.coin(10.0);
    a.coin(15.0);
    EXPECT_EQ(a.cash, 25.0);
}

TEST(AutomataTest, CancelReturnsMoney) {
    Automata a;
    a.on();
    a.coin(20.0);
    a.cancel();
    EXPECT_EQ(a.cash, 0.0);
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, ChoiceSuccessful) {
    Automata a;
    a.on();
    a.coin(30.0);
    bool result = a.choice(2);
    EXPECT_TRUE(result);
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, ChoiceNotEnoughMoney) {
    Automata a;
    a.on();
    a.coin(5.0);
    bool result = a.choice(2);
    EXPECT_FALSE(result);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

TEST(AutomataTest, ChangeReturned) {
    Automata a;
    a.on();
    a.coin(30.0);
    a.choice(1);
    EXPECT_EQ(a.cash, 0.0);
}

TEST(AutomataTest, InvalidChoiceReturnsFalse) {
    Automata a;
    a.on();
    a.coin(30.0);
    bool result = a.choice(99);
    EXPECT_FALSE(result);
}

TEST(AutomataTest, CoinNotAcceptedWhenOff) {
    Automata a;
    a.coin(10.0);
    EXPECT_EQ(a.cash, 0.0);
}