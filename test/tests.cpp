// Copyright 2022 GHA Test Team
// Copyright 2024 GHA Test Team

#include <gtest/gtest.h>

#include "../include/Automata.h"

TEST(AutomataTest, InitialStateIsOff) {
    Automata vm;
    EXPECT_EQ(vm.getState(), STATES::OFF);
    EXPECT_EQ(vm.getCash(), 0);
}

TEST(AutomataTest, OnChangesStateToWait) {
    Automata vm;
    EXPECT_TRUE(vm.on());
    EXPECT_EQ(vm.getState(), STATES::WAIT);
}

TEST(AutomataTest, OffFromWaitChangesStateToOff) {
    Automata vm;
    vm.on();
    EXPECT_TRUE(vm.off());
    EXPECT_EQ(vm.getState(), STATES::OFF);
}

TEST(AutomataTest, CoinInWaitStateChangesToAccept) {
    Automata vm;
    vm.on();
    EXPECT_TRUE(vm.coin(50));
    EXPECT_EQ(vm.getState(), STATES::ACCEPT);
    EXPECT_EQ(vm.getCash(), 50);
}

TEST(AutomataTest, CoinInAcceptStateAccumulates) {
    Automata vm;
    vm.on();
    vm.coin(25);
    vm.coin(25);
    vm.coin(50);
    EXPECT_EQ(vm.getCash(), 100);
    EXPECT_EQ(vm.getState(), STATES::ACCEPT);
}

TEST(AutomataTest, ChoiceChangesStateToCheck) {
    Automata vm;
    vm.on();
    vm.coin(100);
    EXPECT_TRUE(vm.choice(0));
    EXPECT_EQ(vm.getState(), STATES::CHECK);
}

TEST(AutomataTest, CheckReturnsTrueWithSufficientFunds) {
    Automata vm;
    vm.on();
    vm.coin(75);
    vm.choice(1);
    EXPECT_TRUE(vm.check());
}

TEST(AutomataTest, CheckReturnsFalseWithInsufficientFunds) {
    Automata vm;
    vm.on();
    vm.coin(50);
    vm.choice(1);
    EXPECT_FALSE(vm.check());
}

TEST(AutomataTest, CookDeductsPriceAndChangesState) {
    Automata vm;
    vm.on();
    vm.coin(75);
    vm.choice(1);
    EXPECT_TRUE(vm.cook());
    EXPECT_EQ(vm.getState(), STATES::COOK);
    EXPECT_EQ(vm.getCash(), 0);
}

TEST(AutomataTest, FinishReturnsToWaitState) {
    Automata vm;
    vm.on();
    vm.coin(75);
    vm.choice(1);
    vm.cook();
    EXPECT_TRUE(vm.finish());
    EXPECT_EQ(vm.getState(), STATES::WAIT);
    EXPECT_EQ(vm.getCash(), 0);
}

TEST(AutomataTest, CancelRefundsAndReturnsToWait) {
    Automata vm;
    vm.on();
    vm.coin(100);
    EXPECT_TRUE(vm.cancel());
    EXPECT_EQ(vm.getState(), STATES::WAIT);
    EXPECT_EQ(vm.getCash(), 0);
}

TEST(AutomataTest, CoinFailsWhenOff) {
    Automata vm;
    bool result = vm.coin(50);
    EXPECT_FALSE(result);
    EXPECT_EQ(vm.getState(), STATES::OFF);
}
