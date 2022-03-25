// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(taskA, test1) {
  Automata Machine = Automata();
  Machine.on();
  State res = Machine.getState();
  EXPECT_EQ(Wait, res);
}

TEST(taskA, test2) {
  Automata Machine = Automata();
  Machine.on();
  Machine.coin(5);
  int change = Machine.cancel();
  EXPECT_EQ(5, change);
}

TEST(taskA, test3) {
  Automata Machine = Automata();
  Machine.on();
  Machine.coin(5);
  int index = Machine.choice("Black tea");
  bool res = Machine.getState();
  EXPECT_EQ(false, res);
}

TEST(taskA, test4) {
  Automata Machine = Automata();
  Machine.on();
  Machine.coin(50000);
  int index = Machine.choice("Black tea");
  bool res = Machine.getState();
  EXPECT_EQ(true, res);
}

TEST(taskA, test5) {
  Automata Machine = Automata();
  Machine.on();
  Machine.off();
  States res = Machine.getState();
  EXPECT_EQ(Off, res);
}
