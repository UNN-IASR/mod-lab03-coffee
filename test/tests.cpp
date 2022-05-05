// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
TEST(task1, test1) {
    Automata avtomat = Automata();
    avtomat.on();
    STATES result = avtomat.getState();
    EXPECT_EQ(WAIT, result);
}
TEST(task2, test2) {
    Automata avtomat = Automata();
    avtomat.on();
    avtomat.coin(500);
    avtomat.choice(1);
    STATES result = avtomat.getState();
    EXPECT_EQ(CHECK, result);
}
TEST(task3, test3) {
    Automata avtomat = Automata();
    avtomat.on();
    avtomat.coin(200);
    avtomat.choice(1);
    avtomat.cook();
    avtomat.finish();
    STATES result = avtomat.getState();
    EXPECT_EQ(WAIT, result);
}
