// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(0);
    automata.check();
    automata.cook();
    automata.finish();
    automata.off();
    EXPECT_EQ(Automata::States::OFF, automata.getState());
}

TEST(task1, test2) {
    Automata automata;
    automata.on();
    automata.coin(1);
    automata.choice(0);
    automata.cook();
    EXPECT_EQ(Automata::States::WAIT, automata.getState());
}

TEST(task1, test3) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(3);
    automata.cancel();
    EXPECT_EQ(Automata::States::WAIT, automata.getState());
}

TEST(task1, test4) {
    Automata automata;
    automata.on();
    automata.coin(2);
    automata.choice(3);
    automata.cook();
    EXPECT_EQ(Automata::States::WAIT, automata.getState());
}
