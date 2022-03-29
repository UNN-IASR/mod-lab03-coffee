// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(case1, test1) {
    Automata automat = Automata();
    automat.on();
    automat.coin(10);
    automat.choice(1);
    automat.cook();
    STATE state = automat.getState();
    EXPECT_EQ(CHECK, state);
}

TEST(case2, test2) {
    Automata automat = Automata();
    automat.on();
    automat.coin(60);
    automat.choice(2);
    automat.cook();
    automat.cancel();
    automat.finish();
    STATE state = automat.getState();
    EXPECT_EQ(WAIT, state);
}

TEST(case3, test3) {
    Automata automat = Automata();
    automat.on();
    automat.coin(60);
    automat.choice(2);
    automat.cook();
    automat.finish();
    float cash = automat.off();
    EXPECT_EQ(10, cash);
}

TEST(case4, test4) {
    Automata automat = Automata();
    automat.on();
    automat.cook();
    automat.choice(2);
    STATE state = automat.getState();
    EXPECT_EQ(WAIT, state);
}

TEST(case5, test5) {
    Automata automat = Automata();
    automat.on();
    automat.coin(40);
    automat.choice(2);
    automat.cook();
    automat.cancel();
    automat.coin(40);
    automat.choice(2);
    automat.cook();
    automat.finish();
    float cash = automat.off();
    EXPECT_EQ(30, cash);
}
