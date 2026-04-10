// Copyright 2024 GHA Test Team

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "Automata.h"

class AutomataTest : public ::testing::Test {
 protected:
    std::vector<std::string> menu  = {"Кофе", "Чай", "Какао"};
    std::vector<double>      prices = {50.0,   30.0,  45.0};
    Automata* machine;

    void SetUp() override {
        machine = new Automata(menu, prices);
    }
    void TearDown() override {
        delete machine;
    }
};


TEST_F(AutomataTest, InitialStateIsOff) {
    EXPECT_EQ(machine->getState(), STATES::OFF);
}

TEST_F(AutomataTest, OnSwitchesToWait) {
    machine->on();
    EXPECT_EQ(machine->getState(), STATES::WAIT);
}

TEST_F(AutomataTest, OffSwitchesToOff) {
    machine->on();
    machine->off();
    EXPECT_EQ(machine->getState(), STATES::OFF);
}

TEST_F(AutomataTest, OffDoesNothingWhenOff) {
    machine->off();
    EXPECT_EQ(machine->getState(), STATES::OFF);
}

TEST_F(AutomataTest, CoinSwitchesToAcceptAndAccumulates) {
    machine->on();
    machine->coin(20.0);
    EXPECT_EQ(machine->getState(), STATES::ACCEPT);
    EXPECT_DOUBLE_EQ(machine->getCash(), 20.0);

    machine->coin(15.0);
    EXPECT_DOUBLE_EQ(machine->getCash(), 35.0);
    EXPECT_EQ(machine->getState(), STATES::ACCEPT);
}

TEST_F(AutomataTest, CoinIgnoredWhenOff) {
    machine->coin(10.0);
    EXPECT_DOUBLE_EQ(machine->getCash(), 0.0);
    EXPECT_EQ(machine->getState(), STATES::OFF);
}

TEST_F(AutomataTest, ChoiceSwitchesToCheck) {
    machine->on();
    machine->coin(50.0);
    machine->choice(0);
    EXPECT_EQ(machine->getState(), STATES::CHECK);
    EXPECT_EQ(machine->getSelectedDrink(), 0);
}

TEST_F(AutomataTest, ChoiceInvalidIndexKeepsAccept) {
    machine->on();
    machine->coin(50.0);
    machine->choice(99);
    EXPECT_EQ(machine->getState(), STATES::ACCEPT);
}

TEST_F(AutomataTest, CancelFromAcceptResetsCashAndGoesToWait) {
    machine->on();
    machine->coin(40.0);
    machine->cancel();
    EXPECT_EQ(machine->getState(), STATES::WAIT);
    EXPECT_DOUBLE_EQ(machine->getCash(), 0.0);
}

TEST_F(AutomataTest, CancelFromCheckGoesToWait) {
    machine->on();
    machine->coin(50.0);
    machine->choice(0);
    machine->cancel();
    EXPECT_EQ(machine->getState(), STATES::WAIT);
    EXPECT_DOUBLE_EQ(machine->getCash(), 0.0);
}

TEST_F(AutomataTest, CheckWithEnoughMoneyCompletesOrder) {
    machine->on();
    machine->coin(60.0);
    machine->choice(0);
    machine->check();
    EXPECT_EQ(machine->getState(), STATES::WAIT);
    EXPECT_DOUBLE_EQ(machine->getCash(), 0.0);
}

TEST_F(AutomataTest, CheckWithInsufficientMoneyGoesBackToAccept) {
    machine->on();
    machine->coin(20.0);
    machine->choice(0);
    machine->check();
    EXPECT_EQ(machine->getState(), STATES::ACCEPT);
}

TEST_F(AutomataTest, FullCycleEndInWait) {
    machine->on();
    machine->coin(30.0);
    machine->choice(1);
    machine->check();
    EXPECT_EQ(machine->getState(), STATES::WAIT);
}

TEST_F(AutomataTest, GetMenuReturnsCorrectMenu) {
    auto m = machine->getMenu();
    ASSERT_EQ(m.size(), menu.size());
    for (size_t i = 0; i < menu.size(); i++) {
        EXPECT_EQ(m[i], menu[i]);
    }
}

TEST_F(AutomataTest, GetPricesReturnsCorrectPrices) {
    auto p = machine->getPrices();
    ASSERT_EQ(p.size(), prices.size());
    for (size_t i = 0; i < prices.size(); i++) {
        EXPECT_DOUBLE_EQ(p[i], prices[i]);
    }
}

TEST_F(AutomataTest, ConstructorThrowsOnSizeMismatch) {
    std::vector<std::string> badMenu   = {"Кофе", "Чай"};
    std::vector<double>      badPrices = {50.0};
    EXPECT_THROW(Automata bad(badMenu, badPrices), std::invalid_argument);
}

TEST_F(AutomataTest, DoubleOnKeepsWait) {
    machine->on();
    machine->on();
    EXPECT_EQ(machine->getState(), STATES::WAIT);
}

TEST_F(AutomataTest, MultipleCoinsSumCorrectly) {
    machine->on();
    machine->coin(10.0);
    machine->coin(10.0);
    machine->coin(10.0);
    EXPECT_DOUBLE_EQ(machine->getCash(), 30.0);
}
