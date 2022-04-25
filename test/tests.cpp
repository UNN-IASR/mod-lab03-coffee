// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(taskA, test1) {
  Automata Machine = Automata();
  Machine.on();
  STATES res = Machine.getStates();
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
  Machine.coin(15);
  int index = Machine.choice("tea");
  bool res = Machine.check(index);
  EXPECT_EQ(false, res);
}

TEST(taskA, test4) {
  Automata Machine = Automata();
  Machine.on();
  Machine.coin(70);
  int index = Machine.choice("tea");
  bool res = Machine.check(index);
  EXPECT_EQ(true, res);
}

TEST(taskA, test5) {
  Automata Machine = Automata();
  Machine.on();
  Machine.off();
  STATES res = Machine.getStates();
  EXPECT_EQ(Off, res);
}
