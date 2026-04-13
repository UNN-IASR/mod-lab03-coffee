// Copyright 2026 EnganK

#include <gtest/gtest.h>
#include "Automata.h"
#include "../include/Automata.h"

TEST(AutomataTest, InitialStateIsOff) {
    Automata a;
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, OnChangesStateToWait) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, OffFromWaitChangesStateToOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, CoinFromWaitChangesStateToAccept) {
    Automata a;
    a.on();
    a.coin(10);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

TEST(AutomataTest, CancelFromAcceptChangesStateToWait) {
    Automata a;
    a.on();
    a.coin(20);
    a.cancel();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, ChoiceWithoutCoinKeepsStateWait) {
    Automata a;
    a.on();
    a.choice(0);
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, ChoiceAfterCoinChangesStateToCheck) {
    Automata a;
    a.on();
    a.coin(30);
    a.choice(0);
    EXPECT_EQ(a.getState(), STATES::CHECK);
}

TEST(AutomataTest, CheckChangesStateToCook) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(0);
    a.check();
    EXPECT_EQ(a.getState(), STATES::COOK);
}

TEST(AutomataTest, CancelFromCheckChangesStateToWait) {
    Automata a;
    a.on();
    a.coin(5);
    a.choice(0);
    a.check();
    a.cancel();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, FinishAfterCookChangesStateToWait) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);
    a.check();
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}
