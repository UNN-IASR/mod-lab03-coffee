// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
    Automata newAutomata = Automata();
    newAutomata.on();
    states result = newAutomata.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task2, test2) {
    Automata newAutomata = Automata();
    newAutomata.on();
    newAutomata.coin(100);
    states result = newAutomata.getState();
    EXPECT_EQ(ACCEPT, result);
}

TEST(task3, test3) {
    Automata newAutomata = Automata();
    newAutomata.on();
    newAutomata.coin(200);
    newAutomata.choice(3);
    states result = newAutomata.getState();
    EXPECT_EQ(CHECK, result);
}

TEST(task4, test4) {
    Automata newAutomata = Automata();
    newAutomata.on();
    newAutomata.coin(200);
    newAutomata.choice(3);
    newAutomata.cook();
    states result = newAutomata.getState();
    EXPECT_EQ(COOK, result);
}

TEST(task5, test5) {
    Automata newAutomata = Automata();
    newAutomata.on();
    newAutomata.coin(200);
    newAutomata.choice(3);
    newAutomata.cook();
    newAutomata.finish();
    states result = newAutomata.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task6, test6) {
    Automata newAutomata = Automata();
    newAutomata.on();
    newAutomata.coin(200);
    newAutomata.choice(3);
    newAutomata.cook();
    newAutomata.finish();
    newAutomata.off();
    states result = newAutomata.getState();
    EXPECT_EQ(OFF, result);
}
