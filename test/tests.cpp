// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
TEST(TEST1, TrueOrFalse) {
    Automata automata;
    automata.on();
    EXPECT_EQ(States::WAIT, automata.getState());
}

TEST(TEST2, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(250);
    automata.coin(300);
    EXPECT_EQ(States::ACCEPT, automata.getState());
}

TEST(TEST3, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(250);
    automata.coin(300);
    automata.choiceuser(3);
    EXPECT_EQ(States::ACCEPT, automata.getState());
}

TEST(TEST4, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(250);
    automata.coin(300);
    automata.choiceuser(3);
    automata.check();
    EXPECT_EQ(States::COOK, automata.getState());
}

TEST(TEST5, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(800);
    automata.choiceuser(5);
    automata.check();
    automata.cook();
    EXPECT_EQ(300, automata.getCash());
}

TEST(TEST6, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(800);
    automata.choiceuser(5);
    automata.check();
    automata.cook();
    automata.finish();
    automata.off();
    EXPECT_EQ(States::OFF, automata.getState());
}
