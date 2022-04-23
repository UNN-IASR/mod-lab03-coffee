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
    automata.coin(900);
    EXPECT_EQ(States::ACCEPT, automata.getState());
}

TEST(TEST3, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(1000);
    automata.choiceuser(0);
    EXPECT_EQ(States::ACCEPT, automata.getState());
}

TEST(TEST4, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(500);
    automata.coin(1000);
    automata.choiceuser(0);
    automata.check();
    EXPECT_EQ(States::COOK, automata.getState());
}

TEST(TEST5, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(400);
    automata.choiceuser(1);
    automata.check();
    automata.cook();
    EXPECT_EQ(100, automata.getCash());
}

TEST(TEST6, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(200);
    automata.choiceuser(0);
    automata.check();
    automata.cook();
    automata.finish();
    automata.off();
    EXPECT_EQ(States::OFF, automata.getState());
}
