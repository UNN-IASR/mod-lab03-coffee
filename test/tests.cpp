// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialState) {
  Automata a;

  EXPECT_EQ(a.getState(), "OFF");
  EXPECT_EQ(a.getCash(), 0);
  EXPECT_EQ(a.getNumberSelectedDrink(), 0);
}

TEST(AutomataTest, AutomataON) {
  Automata a;
  a.on();

  EXPECT_EQ(a.getState(), "WAIT");
}

TEST(AutomataTest, AutomataOFF) {
  Automata a;
  a.on();
  a.off();

  EXPECT_EQ(a.getState(), "OFF");
}

TEST(AutomataTest, AcceptCoin) {
  Automata a;
  a.on();
  a.coin(50);
  a.coin(15);

  EXPECT_EQ(a.getState(), "ACCEPT");
  EXPECT_EQ(a.getCash(), 65);
}

TEST(AutomataTest, StateCheck) {
  Automata a;
  a.on();
  a.coin(80);
  a.choice(3);

  EXPECT_EQ(a.getNumberSelectedDrink(), 3);
  EXPECT_EQ(a.getState(), "CHECK");
}

TEST(AutomataTest, CheckTrue) {
  Automata a;
  a.on();
  a.coin(50);
  a.choice(1);

  EXPECT_EQ(a.getNumberSelectedDrink(), 1);
  EXPECT_TRUE(a.check());
}

TEST(AutomataTest, CheckFalse) {
  Automata a;
  a.on();
  a.coin(50);
  a.choice(4);

  EXPECT_EQ(a.getNumberSelectedDrink(), 4);
  EXPECT_FALSE(a.check());
}

TEST(AutomataTest, CancelWithRefund) {
  Automata a;
  a.on();
  a.coin(50);
  a.choice(1);
  a.cancel();

  EXPECT_EQ(a.getCash(), 0);
  EXPECT_EQ(a.getNumberSelectedDrink(), 0);
  EXPECT_EQ(a.getState(), "WAIT");
}

TEST(AutomataTest, NotCook) {
  Automata a;
  a.on();
  a.coin(50);
  a.choice(2);
  a.cook();

  EXPECT_EQ(a.getCash(), 50);
  EXPECT_EQ(a.getNumberSelectedDrink(), 2);
  EXPECT_EQ(a.getState(), "CHECK");
}

TEST(AutomataTest, Cook) {
  Automata a;
  a.on();
  a.coin(55);
  a.choice(2);
  a.cook();

  EXPECT_EQ(a.getCash(), 0);
  EXPECT_EQ(a.getNumberSelectedDrink(), 0);
  EXPECT_EQ(a.getState(), "WAIT");
}

TEST(AutomataTest, DontChoice) {
  Automata a;
  a.on();
  a.choice(2);

  EXPECT_EQ(a.getNumberSelectedDrink(), 0);
  EXPECT_EQ(a.getState(), "WAIT");
}
