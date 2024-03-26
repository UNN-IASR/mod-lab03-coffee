// Copyright 2024 Kokorin Alexandr

#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public testing::Test {
 protected:
    Automata vendingMachine;
};

TEST(AutomataTest, TurnOn) {
    Automata vendingMachine;
    vendingMachine.on();
    EXPECT_EQ(WAIT, vendingMachine.getState());
}

TEST(AutomataTest, TurnOff) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.off();
    EXPECT_EQ(OFF, vendingMachine.getState());
}

TEST(AutomataTest, DrinkSelection) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.coin(100);
    vendingMachine.getMenu();
    vendingMachine.choice(1);
    EXPECT_EQ(CHECK, vendingMachine.getState());
}

TEST(AutomataTest, CancelOrder) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.coin(200);
    vendingMachine.cancel();
    EXPECT_EQ(WAIT, vendingMachine.getState());
}

TEST(AutomataTest, InvalidNumber) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.coin(200);
    vendingMachine.choice(10);
    EXPECT_EQ(CHECK, vendingMachine.getState());
}

TEST(AutomataTest, NoMoneyNoDrink) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.choice(1);
    EXPECT_EQ(WAIT, vendingMachine.getState());
}

TEST(AutomataTest, ReDepositingMoney) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.coin(50);
    vendingMachine.choice(8);
    vendingMachine.coin(50);
    vendingMachine.choice(8);
    EXPECT_EQ(CHECK, vendingMachine.getState());
}

TEST(AutomataTest, OffMachine) {
    Automata vendingMachine;
    vendingMachine.off();
    EXPECT_EQ(OFF, vendingMachine.getState());
}

TEST(AutomataTest, MoneyAdding) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.coin(20);
    vendingMachine.coin(10);
    vendingMachine.coin(20);
    EXPECT_EQ(ACCEPT, vendingMachine.getState());
}

TEST(AutomataTest, TwoCycles) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.coin(100);
    vendingMachine.coin(20);
    vendingMachine.coin(20);
    vendingMachine.choice(3);
    vendingMachine.coin(0);
    vendingMachine.choice(2);
    EXPECT_EQ(CHECK, vendingMachine.getState());
}
