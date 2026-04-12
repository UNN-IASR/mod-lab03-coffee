// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialStateIsOff) {
    Automata a;
    ASSERT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, OnChangesStateToWait) {
    Automata a;
    a.on();
    ASSERT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, OffKeepsStateOff) {
    Automata a;
    a.off();
    ASSERT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, CoinInWaitChangesStateToAccept) {
    Automata a;
    a.on();
    a.coin(50);
    ASSERT_EQ(a.getState(), STATES::ACCEPT);
}

TEST(AutomataTest, ChoiceChangesStateToCheck) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    ASSERT_EQ(a.getState(), STATES::CHECK);
}

TEST(AutomataTest, CheckReturnsTrueWhenEnoughMoney) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    ASSERT_TRUE(a.check());
}

TEST(AutomataTest, CheckReturnsFalseWhenNotEnoughMoney) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    ASSERT_FALSE(a.check());
}

TEST(AutomataTest, CheckWithoutEnoughMoneyReturnsToWait) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    a.check();
    ASSERT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, CookChangesStateToCook) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    ASSERT_TRUE(a.check());
    a.cook();
    ASSERT_EQ(a.getState(), STATES::COOK);
}

TEST(AutomataTest, FinishChangesStateToWait) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    ASSERT_TRUE(a.check());
    a.cook();
    a.finish();
    ASSERT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, CancelChangesStateToWait) {
    Automata a;
    a.on();
    a.coin(50);
    a.cancel();
    ASSERT_EQ(a.getState(), STATES::WAIT);
}
