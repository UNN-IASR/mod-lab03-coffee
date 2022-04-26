// Copyright 2022 UNN-IASR
#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
    Automata a = Automata();
    a.on();
    a.cancel();
    int result = a.getState();
    EXPECT_EQ(1, result);
}

TEST(task2, test2) {
    Automata a = Automata();
    a.on();
    a.coin(1);
    a.choice(1);
    int result = a.getState();
    EXPECT_EQ(2, result);
}

TEST(task3, test3) {
    Automata a = Automata();
    a.on();
    a.coin(200);
    a.choice(1);
    int result = a.getState();
    EXPECT_EQ(4, result);
}

TEST(task4, test4) {
    Automata a = Automata();
    a.on();
    a.coin(100);
    a.choice(2);
    a.coin(100);
    a.choice(2);
    int result = a.getState();
    EXPECT_EQ(4, result);
}
