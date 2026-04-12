// Copyright 2026 UNN-IASR

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, Test1) {
    Automata a;
    EXPECT_EQ(a.getState(), OFF);
    a.on();
    EXPECT_EQ(a.getState(), WAIT);
    a.off();
    EXPECT_EQ(a.getState(), OFF);
}
TEST(AutomataTest, Test2) {
    Automata a;
    a.on();
    a.coin(100);
    EXPECT_EQ(a.getState(), ACCEPT);
    a.choice(1);
    EXPECT_EQ(a.getState(), WAIT);
}
TEST(AutomataTest, Test3) {
    Automata a;
    a.on();
    a.coin(50);
    EXPECT_EQ(a.getState(), ACCEPT);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
}
TEST(AutomataTest, Test4) {
    Automata a;
    a.on();
    a.coin(20);
    EXPECT_EQ(a.getState(), ACCEPT);
    a.coin(20);
    EXPECT_EQ(a.getState(), ACCEPT);
}
TEST(AutomataTest, Test5) {
    Automata a;
    a.on();
    a.coin(20);
    EXPECT_EQ(a.getState(), ACCEPT);
    a.choice(2);
    EXPECT_EQ(a.getState(), CHECK);
    a.coin(20);
    EXPECT_EQ(a.getState(), CHECK);
    a.coin(20);
    EXPECT_EQ(a.getState(), WAIT);
}
TEST(AutomataTest, Test6) {
    Automata a;
    a.on();
    a.coin(40);
    EXPECT_EQ(a.getState(), ACCEPT);
    a.choice(2);
    EXPECT_EQ(a.getSelectedDrink(), 2);
    EXPECT_EQ(a.getState(), CHECK);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
    a.off();
    EXPECT_EQ(a.getState(), OFF);
}
TEST(AutomataTest, Test7) {
    Automata a;
    a.on();
    a.coin(100);
    EXPECT_EQ(a.getState(), ACCEPT);
    a.choice(6);
    EXPECT_EQ(a.getState(), ACCEPT);
}
TEST(AutomataTest, Test8) {
    Automata a;
    a.on();
    a.coin(100);
    a.off();
    EXPECT_EQ(a.getState(), ACCEPT);
}
TEST(AutomataTest, Test9) {
    Automata a;
    a.coin(100);
    EXPECT_EQ(a.getState(), OFF);
}
TEST(AutomataTest, Test10) {
    Automata a;
    a.on();
    a.coin(10);
    a.coin(10);
    a.coin(10);
    EXPECT_EQ(a.getCash(), 30);
    EXPECT_EQ(a.getState(), ACCEPT);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
}
TEST(AutomataTest, Test11) {
    Automata a;
    a.on();
    a.choice(0);
    EXPECT_EQ(a.getState(), WAIT);
}
