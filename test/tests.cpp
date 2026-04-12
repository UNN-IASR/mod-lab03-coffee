#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialStateIsOff)
{
    Automata vm;
    EXPECT_EQ(vm.getState(), STATES::OFF);
}

TEST(AutomataTest, OnChangesStateToWait)
{
    Automata vm;
    vm.on();
    EXPECT_EQ(vm.getState(), STATES::WAIT);
}

TEST(AutomataTest, OffFromWaitChangesStateToOff)
{
    Automata vm;
    vm.on();
    vm.off();
    EXPECT_EQ(vm.getState(), STATES::OFF);
}

TEST(AutomataTest, CoinInWaitStateChangesToAccept)
{
    Automata vm;
    vm.on();
    vm.coin(50);
    EXPECT_EQ(vm.getState(), STATES::ACCEPT);
    EXPECT_EQ(vm.getCash(), 50);
}

TEST(AutomataTest, CoinInAcceptStateAccumulates)
{
    Automata vm;
    vm.on();
    vm.coin(25);
    vm.coin(25);
    vm.coin(50);
    EXPECT_EQ(vm.getCash(), 100);
    EXPECT_EQ(vm.getState(), STATES::ACCEPT);
}

TEST(AutomataTest, ChoiceChangesStateToCheck)
{
    Automata vm;
    vm.on();
    vm.coin(100);
    vm.choice(0);
    EXPECT_EQ(vm.getState(), STATES::CHECK);
}

TEST(AutomataTest, CheckReturnsTrueWithSufficientFunds)
{
    Automata vm;
    vm.on();
    vm.coin(75);
    vm.choice(1);
    EXPECT_TRUE(vm.check());
}

TEST(AutomataTest, CheckReturnsFalseWithInsufficientFunds)
{
    Automata vm;
    vm.on();
    vm.coin(50);
    vm.choice(1);
    EXPECT_FALSE(vm.check());
}

TEST(AutomataTest, CookDeductsPriceAndChangesState)
{
    Automata vm;
    vm.on();
    vm.coin(75);
    vm.choice(1);
    vm.cook();
    EXPECT_EQ(vm.getState(), STATES::COOK);
    EXPECT_EQ(vm.getCash(), 0);
}

TEST(AutomataTest, FinishReturnsToWaitState)
{
    Automata vm;
    vm.on();
    vm.coin(75);
    vm.choice(1);
    vm.cook();
    vm.finish();
    EXPECT_EQ(vm.getState(), STATES::WAIT);
    EXPECT_EQ(vm.getCash(), 0);
}

TEST(AutomataTest, CancelRefundsAndReturnsToWait)
{
    Automata vm;
    vm.on();
    vm.coin(100);
    vm.cancel();
    EXPECT_EQ(vm.getState(), STATES::WAIT);
    EXPECT_EQ(vm.getCash(), 0);
}

TEST(AutomataTest, CoinFailsWhenOff)
{
    Automata vm;
    bool result = vm.coin(50);
    EXPECT_FALSE(result);
    EXPECT_EQ(vm.getState(), STATES::OFF);
}

TEST(AutomataTest, ChoiceFailsWithInvalidIndex)
{
    Automata vm;
    vm.on();
    vm.coin(100);
    bool result = vm.choice(99);
    EXPECT_FALSE(result);
    EXPECT_EQ(vm.getState(), STATES::ACCEPT);
}

TEST(AutomataTest, CookFailsWithoutSufficientFunds)
{
    Automata vm;
    vm.on();
    vm.coin(20);
    vm.choice(0);
    bool result = vm.cook();
    EXPECT_FALSE(result);
    EXPECT_EQ(vm.getState(), STATES::CHECK);
}

TEST(AutomataTest, OffFailsDuringTransaction)
{
    Automata vm;
    vm.on();
    vm.coin(50);
    bool result = vm.off();
    EXPECT_FALSE(result);
    EXPECT_EQ(vm.getState(), STATES::ACCEPT);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}