// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "../include/Automata.h"

TEST(AutomataTest, Off) {
    Automata a;
    EXPECT_EQ(a.getState(), STATES::OFF);
    EXPECT_EQ(a.getCash(), 0);
    EXPECT_EQ(a.getSelectedItem(), -1);
}

TEST(AutomataTest, On) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), STATES::WAIT);
    EXPECT_EQ(a.getCash(), 0);
}

TEST(AutomataTest, OnOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, CoinFromWait) {
    Automata a;
    a.on();
    a.coin(100);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
    EXPECT_EQ(a.getCash(), 100);
}

TEST(AutomataTest, CoinMultiple) {
    Automata a;
    a.on();
    a.coin(50);
    a.coin(30);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
    EXPECT_EQ(a.getCash(), 80);
}

TEST(AutomataTest, ChoiceValid) {
    Automata a;
    a.on();
    a.coin(100);
    bool ok = a.choice(1);
    EXPECT_TRUE(ok);
    EXPECT_EQ(a.getState(), STATES::CHECK);
    EXPECT_EQ(a.getSelectedItem(), 0);
}

TEST(AutomataTest, ChoiceInvalid) {
    Automata a;
    a.on();
    a.coin(100);
    bool ok = a.choice(10);
    EXPECT_FALSE(ok);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
    EXPECT_EQ(a.getSelectedItem(), -1);
}

TEST(AutomataTest, CheckEnough) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(2);
    bool enough = a.check();
    EXPECT_TRUE(enough);
    EXPECT_EQ(a.getState(), STATES::COOK);
}

TEST(AutomataTest, CheckNotEnough) {
    Automata a;
    a.on();
    a.coin(20);
    a.choice(3);
    bool enough = a.check();
    EXPECT_FALSE(enough);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
    EXPECT_EQ(a.getCash(), 20);
}

TEST(AutomataTest, CancelFromAccept) {
    Automata a;
    a.on();
    a.coin(50);
    a.cancel();
    EXPECT_EQ(a.getState(), STATES::WAIT);
    EXPECT_EQ(a.getCash(), 0);
    EXPECT_EQ(a.getSelectedItem(), -1);
}

TEST(AutomataTest, CancelFromCheck) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    a.cancel();
    EXPECT_EQ(a.getState(), STATES::WAIT);
    EXPECT_EQ(a.getCash(), 0);
}

TEST(AutomataTest, FullWork) {
    Automata a;
    a.on();
    a.coin(80);
    a.choice(4);
    EXPECT_TRUE(a.check());
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), STATES::WAIT);
    EXPECT_EQ(a.getCash(), 0);
    EXPECT_EQ(a.getSelectedItem(), -1);
}

TEST(AutomataTest, ChoiceExtremeNumbers) {
    Automata a;
    a.on();
    a.coin(100);
    EXPECT_TRUE(a.choice(1));
    EXPECT_EQ(a.getSelectedItem(), 0);
    a.cancel();

    a.coin(100);
    EXPECT_TRUE(a.choice(7));
    EXPECT_EQ(a.getSelectedItem(), 6);
}
