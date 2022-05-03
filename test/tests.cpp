// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(TestCoffee, TestOn) {
    Automata a { };
    a.on();
    EXPECT_TRUE(a.getState() == STATES::WAIT);
}

TEST(TestCoffee, TestAccept) {
    Automata a { };
    a.on();
    a.coin(5);
    EXPECT_TRUE(a.getState() == STATES::ACCEPT);
}

TEST(TestCoffee, TestCoin) {
    Automata a { };
    a.on();
    a.coin(5);
    EXPECT_EQ(5, a.getRest());
}

TEST(TestCoffee, TestCheck) {
    Automata a { };
    a.on();
    a.coin(5);
    a.choice();
    EXPECT_TRUE(a.getState() == STATES::CHECK);
}

TEST(TestCoffee, TestCancel) {
    Automata a { };
    a.on();
    a.coin(5);
    a.choice();
    if (!a.check("Latte"))
        a.cancel();
    EXPECT_TRUE(a.getState() == STATES::WAIT);
}

TEST(TestCoffee, TestCook) {
    Automata a { };
    a.on();
    a.coin(15);
    a.choice();
    if (a.check("Latte"))
        a.cook();
    EXPECT_TRUE(a.getState() == STATES::COOK);
}

TEST(TestCoffee, TestFinish) {
    Automata a { };
    a.on();
    a.coin(15);
    a.choice();
    if (a.check("Latte"))
        a.cook();
    a.finish();
    EXPECT_TRUE(a.getState() == STATES::WAIT);
}

TEST(TestCoffee, TestOff) {
    Automata a { };
    a.on();
    a.coin(15);
    a.choice();
    if (a.check("Latte"))
        a.cook();
    a.finish();
    a.off();
    EXPECT_TRUE(a.getState() == STATES::OFF);
}

TEST(TestCoffee, TestWorkStatus) {
    Automata a { };
    int result = a.work("Latte", 17);
    EXPECT_TRUE(a.getState() == STATES::OFF);
}

TEST(TestCoffee, TestWorkRest) {
    Automata a { };
    int result = a.work("Latte", 17);
    EXPECT_EQ(7, result);
}
