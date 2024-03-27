// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(fun_on, test1) {
    Automata a;
    a.on();
    EXPECT_EQ(WAIT, a.getState());
}

TEST(fun_off, test2) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(OFF, a.getState());
}

TEST(fun_cancel, test3) {
    Automata a;
    a.on();
    a.coin(100);
    a.cancel();
    EXPECT_EQ(WAIT, a.getState());
}

TEST(fun_coin, test4) {
    Automata a;
    a.on();
    a.coin(100);
    EXPECT_EQ(ACCEPT, a.getState());
}

TEST(cash, test5) {
    Automata a;
    a.on();
    a.coin(100);
    EXPECT_EQ(100, a.getCash());
}

TEST(fun_choic, test6) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(2);
    EXPECT_EQ(ACCEPT, a.getState());
}

TEST(fun_check, test7) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(2);
    EXPECT_EQ(50, a.getCash());
}

TEST(fun_cook, test8) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(2);
    a.coin(100);
    a.choice(2);
    EXPECT_EQ(WAIT, a.getState());
}

TEST(fun_finish, test9) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(2);
    a.coin(100);
    a.choice(2);
    EXPECT_EQ(0, a.getCash());
}

TEST(no_on, test10) {
    Automata a;
    a.coin(50); //ignore
    EXPECT_EQ(OFF, a.getState());
}

TEST(no_coin, test11) {
    Automata a;
    a.on();
    a.choice(2); //ignore
    EXPECT_EQ(WAIT, a.getState());
}

TEST(no_off, test12) {
    Automata a;
    a.on();
    a.coin(50);
    a.off(); //ignore
    EXPECT_EQ(ACCEPT, a.getState());
}