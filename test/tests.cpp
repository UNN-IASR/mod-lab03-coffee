// Copyright 2022 GHA Test Team
// Copyright 2022 UNN-IASR
#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, operation) {
    Automata coffee;
    coffee.state = OFF;
    coffee.on();
    STATES ok = coffee.getState();
    EXPECT_EQ(WAIT, ok);
}
TEST(task2, operation) {
    Automata coffee;
    coffee.state = COOK;
    coffee.on();
    STATES ok = coffee.getState();
    EXPECT_EQ(COOK, ok);
}
TEST(task3, operation) {
    Automata coffee;
    coffee.state = CHECK;
    bool ok = coffee.check();
    EXPECT_EQ(ok, 0);
}
