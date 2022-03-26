// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"


TEST(TEST1, TrueOrFalse) {
    Automata automata;
    automata.on();
    EXPECT_EQ(STATES::WAIT, automata.getState());
}

TEST(TEST2, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(100);
    EXPECT_EQ(STATES::ACCEPT, automata.getState());
}

TEST(TEST3, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.coin(10);
    EXPECT_EQ(STATES::ACCEPT, automata.getState());
}

TEST(TEST4, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(3);
    EXPECT_EQ(STATES::CHEAK, automata.getState());
}

TEST(TEST5, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(3);
    automata.check();
    EXPECT_EQ(STATES::WAIT, automata.getState());
}

TEST(TEST6, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(120);
    automata.choice(3);
    automata.check();
    EXPECT_EQ(STATES::COOK, automata.getState());
}

TEST(TEST7, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(120);
    automata.choice(3);
    automata.check();
    automata.cook();
    EXPECT_EQ(0, automata.getCash());
}

TEST(TEST8, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(120);
    automata.choice(3);
    automata.check();
    automata.cook();
    automata.finish();
    automata.off();
    EXPECT_EQ(STATES::OFF, automata.getState());
}
