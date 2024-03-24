// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public testing::Test {
protected:
    Automata CoffeeBreak;
};

TEST(AutomataTest, TurnOn) {
    Automata CoffeeBreak;
    CoffeeBreak.on();
    EXPECT_EQ(WAIT, CoffeeBreak.getState());
}

TEST(AutomataTest, TurnOff) {
    Automata CoffeeBreak;
    CoffeeBreak.on();
    CoffeeBreak.off();
    EXPECT_EQ(OFF, CoffeeBreak.getState());
}

TEST(AutomataTest, DrinkSelection) {
    Automata CoffeeBreak;
    CoffeeBreak.on();
    CoffeeBreak.coin(50);
    CoffeeBreak.getMenu();
    CoffeeBreak.choice(4);
    EXPECT_EQ(WAIT, CoffeeBreak.getState());
}

TEST(AutomataTest, CancelOrder) {
    Automata CoffeeBreak;
    CoffeeBreak.on();
    CoffeeBreak.coin(200);
    CoffeeBreak.cancel();
    EXPECT_EQ(WAIT, CoffeeBreak.getState());
}

TEST(AutomataTest, InvalidNumber) {
    Automata CoffeeBreak;
    CoffeeBreak.on();
    CoffeeBreak.coin(6);
    CoffeeBreak.choice(7);
    EXPECT_EQ(ACCEPT, CoffeeBreak.getState());
}

TEST(AutomataTest, NoMoneyNoDrink) {
    Automata CoffeeBreak;
    CoffeeBreak.on();
    CoffeeBreak.choice(1);
    EXPECT_EQ(WAIT, CoffeeBreak.getState());
}

TEST(AutomataTest, ReDepositingMoney) {
    Automata CoffeeBreak;
    CoffeeBreak.on();
    CoffeeBreak.coin(20);
    CoffeeBreak.choice(5);
    CoffeeBreak.coin(25);
    CoffeeBreak.choice(5);
    EXPECT_EQ(WAIT, CoffeeBreak.getState());
}

TEST(AutomataTest, OffMachine) {
    Automata CoffeeBreak;
    CoffeeBreak.off();
    EXPECT_EQ(OFF, CoffeeBreak.getState());
}

TEST(AutomataTest, TwoCycles) {
    Automata CoffeeBreak;
    CoffeeBreak.on();
    CoffeeBreak.coin(100);
    CoffeeBreak.coin(20);
    CoffeeBreak.coin(20);
    CoffeeBreak.choice(3);
    CoffeeBreak.coin(0);
    CoffeeBreak.choice(2);
    EXPECT_EQ(ACCEPT, CoffeeBreak.getState());
}
