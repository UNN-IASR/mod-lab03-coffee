// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>

#include <vector>
#include <string>
#include <stdexcept>

#include "Automata.h"

TEST(AutomataTest, DefaultConstructorWorks) {
    Automata a;
    EXPECT_EQ(a.getState(), STATES::OFF);
    EXPECT_EQ(a.getCash(), 0);
}

TEST(AutomataTest, CustomConstructorWrongSizesThrows) {
    EXPECT_THROW(
        Automata({"Tea", "Coffee"}, {30}),
        std::invalid_argument
    );
}

TEST(AutomataTest, CustomConstructorNegativePriceThrows) {
    EXPECT_THROW(
        Automata({"Tea"}, {-10}),
        std::invalid_argument
    );
}

TEST(AutomataTest, OnChangesStateToReady) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), STATES::READY);
}

TEST(AutomataTest, OffResetsEverything) {
    Automata a;
    a.on();
    a.coin(50);
    a.off();

    EXPECT_EQ(a.getState(), STATES::OFF);
    EXPECT_EQ(a.getCash(), 0);
    EXPECT_EQ(a.getSelectedIndex(), -1);
}

TEST(AutomataTest, CoinWhenOffThrows) {
    Automata a;
    EXPECT_THROW(a.coin(10), std::runtime_error);
}

TEST(AutomataTest, CoinAddsMoney) {
    Automata a;
    a.on();
    a.coin(20);

    EXPECT_EQ(a.getCash(), 20);
    EXPECT_EQ(a.getState(), STATES::WAIT_CHOICE);
}

TEST(AutomataTest, CoinWithNegativeAmountThrows) {
    Automata a;
    a.on();
    EXPECT_THROW(a.coin(-5), std::invalid_argument);
}

TEST(AutomataTest, ChoiceWithoutMoneyThrows) {
    Automata a;
    a.on();

    EXPECT_THROW(a.choice(0), std::runtime_error);
    EXPECT_EQ(a.getState(), STATES::WAIT_MONEY);
}

TEST(AutomataTest, InvalidChoiceThrows) {
    Automata a;
    a.on();
    a.coin(100);

    EXPECT_THROW(a.choice(100), std::out_of_range);
}

TEST(AutomataTest, CheckReturnsTrueIfEnoughMoney) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);  // Tea = 30

    EXPECT_TRUE(a.check());
}

TEST(AutomataTest, CheckReturnsFalseIfNotEnoughMoney) {
    Automata a;
    a.on();
    a.coin(20);
    a.choice(1);  // Coffee = 50

    EXPECT_FALSE(a.check());
}

TEST(AutomataTest, CookWithEnoughMoneyWorks) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);  // Tea = 30

    std::string result = a.cook();

    EXPECT_EQ(a.getState(), STATES::COOKING);
    EXPECT_EQ(a.getCash(), 20);
    EXPECT_NE(result.find("Cooking"), std::string::npos);
}

TEST(AutomataTest, CookWithoutEnoughMoneyThrows) {
    Automata a;
    a.on();
    a.coin(20);
    a.choice(1);  // Coffee = 50

    EXPECT_THROW(a.cook(), std::runtime_error);
}

TEST(AutomataTest, FinishAfterCookingWorks) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);  // Coffee = 50
    a.cook();

    std::string result = a.finish();

    EXPECT_EQ(a.getState(), STATES::FINISHED);
    EXPECT_EQ(a.getCash(), 0);
    EXPECT_NE(result.find("Change"), std::string::npos);
}

TEST(AutomataTest, CancelReturnsMoney) {
    Automata a;
    a.on();
    a.coin(40);

    int refund = a.cancel();

    EXPECT_EQ(refund, 40);
    EXPECT_EQ(a.getCash(), 0);
    EXPECT_EQ(a.getState(), STATES::CANCELLED);
}

TEST(AutomataTest, FinishAfterCancelWorks) {
    Automata a;
    a.on();
    a.coin(35);
    a.cancel();

    std::string result = a.finish();

    EXPECT_EQ(a.getState(), STATES::FINISHED);
    EXPECT_NE(result.find("cancelled"), std::string::npos);
}
