// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
    Automata Automat1;
    Automat1.on();
    STATES result = Automat1.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task1, test2) {
    Automata Automat1;
    Automat1.on();
    Automat1.coin(170);
    STATES result = Automat1.getState();
    EXPECT_EQ(ACCEPT, result);
}

TEST(task1, test3) {
    Automata Automat1;
    Automat1.on();
    Automat1.coin(170);
    Automat1.choice(1);
    STATES result = Automat1.getState();
    EXPECT_EQ(CHECK, result);
}

TEST(task1, test4) {
    Automata Automat1;
    Automat1.on();
    Automat1.coin(170);
    Automat1.choice(1);
    Automat1.cook();
    STATES result = Automat1.getState();
    EXPECT_EQ(COOK, result);
}

TEST(task1, test5) {
    Automata Automat1;
    Automat1.on();
    Automat1.coin(170);
    Automat1.choice(1);
    Automat1.cook();
    Automat1.finish();
    STATES result = Automat1.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task1, test6) {
    Automata Automat1;
    Automat1.on();
    Automat1.coin(170);
    Automat1.choice(1);
    Automat1.cook();
    Automat1.finish();
    Automat1.off();
    STATES result = Automat1.getState();
    EXPECT_EQ(OFF, result);
}

TEST(task2, test1) {
    Automata Automat1;
    Automat1.on();
    Automat1.coin(170);
    Automat1.choice(1);
    Automat1.cancel();
    STATES result = Automat1.getState();
    EXPECT_EQ(WAIT, result);
}
