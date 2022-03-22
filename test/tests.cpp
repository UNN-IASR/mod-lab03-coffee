// Copyright 2022 UNN-IASR
#include <gtest/gtest.h>
#include "Automata.h"

TEST(taskA, test1) {
  Automata a = Automata();
  a.on();
  int result = a.getState();
  EXPECT_EQ(WAIT, result);
}

TEST(taskA, test2) {
  Automata a = Automata();
  a.on();
  a.coin(100);
  int result = a.getState();
  EXPECT_EQ(ACCEPT, result);
}

TEST(taskA, test3) {
  Automata a = Automata();
  a.on();
  a.coin(100);
  a.choice(1);
  int result = a.getState();
  EXPECT_EQ(ACCEPT, result);
}

TEST(taskA, test4) {
  Automata a = Automata();
  a.on();
  a.coin(200);
  a.choice(1);
  int result = a.getState();
  EXPECT_EQ(COOK, result);
}

TEST(taskA, test5) {
  Automata a = Automata();
  a.on();
  a.coin(200);
  a.choice(1);
  a.finish();
  int result = a.cancel();
  EXPECT_EQ(80, result);
}

TEST(taskA, test6) {
  Automata a = Automata();
  a.on();
  a.coin(200);
  a.choice(1);
  a.finish();
  a.off();
  int result = a.getState();
  EXPECT_EQ(OFF, result);
}
