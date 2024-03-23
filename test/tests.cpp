// Copyright 2024 alenkaLo
#include "Automata.h"
#include <gtest/gtest.h>

TEST(fun_on, run) {
  Automata a;
  a.on();
  states st = a.getState();
  EXPECT_EQ(state_on, st);
}

TEST(fun_on, ignore) {
    Automata a(state_cook);
    a.on();
    states st = a.getState();
    EXPECT_EQ(state_cook, st);
}
