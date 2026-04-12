// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, TurnOn) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, TurnOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, InsertCoin) {
    Automata a;
    a.on();
    a.coin(50);
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(AutomataTest, ChoiceWithoutMoney) {
    Automata a;
    a.on();
    a.choice(1);
    EXPECT_NE(a.getState(), CHECK);
}

TEST(AutomataTest, NotEnoughMoney) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(1);
    a.check();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, EnoughMoney) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    a.check();
    EXPECT_EQ(a.getState(), COOK);
}

TEST(AutomataTest, Cooking) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    a.check();
    a.cook();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, Finish) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    a.check();
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, Cancel) {
    Automata a;
    a.on();
    a.coin(50);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, MultipleCoins) {
    Automata a;
    a.on();
    a.coin(30);
    a.coin(30);
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(AutomataTest, CookWithoutCheck) {
    Automata a;
    a.on();
    a.coin(100);
    a.cook();
    EXPECT_NE(a.getState(), COOK);
}

TEST(AutomataTest, ChoiceWhenOff) {
    Automata a;
    a.choice(1);
    EXPECT_EQ(a.getState(), OFF);
}
