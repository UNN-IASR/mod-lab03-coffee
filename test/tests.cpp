// Copyright 2024 alenkaLo
#include "Automata.h"
#include <gtest/gtest.h>

TEST(fun_on, test1) {
    Automata a;
    a.on();
    states st = a.getState();
    EXPECT_EQ(state_wait, st);
}

TEST(fun_on, test2) {
    Automata a(state_cook);
    a.on(); //ignore
    states st = a.getState();
    EXPECT_EQ(state_cook, st);
}

TEST(fun_coin, test3) {
    Automata a;
    a.on();
    a.coin(3);
    states st = a.getState();
    EXPECT_EQ(state_accept, st);
}

TEST(fun_choise, test4) {
    Automata a(state_accept);
    a.choice(1);
    states st = a.getState();
    EXPECT_EQ(state_wait, st);
}

TEST(fun_check, test5) {
    Automata a(state_wait);
    a.coin(100);
    a.choice(2);
    a.check();
    states st = a.getState();
    EXPECT_EQ(state_wait, st);
}

TEST(fun_check, test7) {
    Automata a(state_wait);
    a.coin(100);
    a.choice(0);
    a.check();
    states st = a.getState();
    EXPECT_EQ(state_check, st);
}

TEST(fun_cook, test6) {
    Automata a(state_cook);
    a.cook();
    states st = a.getState();
    EXPECT_EQ(state_wait, st);
}

TEST(fun_cancel, test8) {
    Automata a(state_accept);
    a.cancel();
    states st = a.getState();
    EXPECT_EQ(state_wait, st);
}

TEST(fun_all, test9) {
    Automata a;
    a.on();
    a.coin(20);
    a.choice(2);
    a.cancel();
    a.coin(30);
    a.off(); //ignore
    a.choice(2);
    EXPECT_EQ(state_wait, a.getState());
}

TEST(fun_all, test10) {
    Automata a;
    a.on();
    a.setMenu();
    a.coin(200);
    a.choice(0);
    EXPECT_EQ(state_wait, a.getState());
}

