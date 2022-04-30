// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
    Automata first = Automata();
    first.On();
    first.Cancel();
    int result = first.GetState();
    EXPECT_EQ(1, result);
}

TEST(task2, test2) {
    Automata second = Automata();
    second.On();
    second.AddCoin(1);
    second.ChoiceMenu(1);
    int result = second.GetState();
    EXPECT_EQ(2, result);
}

TEST(task3, test3) {
    Automata third = Automata();
    third.On();
    third.AddCoin(200);
    third.ChoiceMenu(1);
    int result = third.GetState();
    EXPECT_EQ(4, result);
}

TEST(task4, test4) {
    Automata fourth = Automata();
    fourth.On();
    fourth.AddCoin(100);
    fourth.ChoiceMenu(2);
    fourth.AddCoin(100);
    fourth.ChoiceMenu(2);
    int result = fourth.GetState();
    EXPECT_EQ(4, result);
}
