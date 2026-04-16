// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>

#include "Automata.h"

TEST(task1, test1) {
  std::stringstream strs;
  Automata* automata = new Automata(strs);
  ASSERT_EQ(STATES::OFF, automata->getState());
  EXPECT_EQ(strs.str(), "OFF\n");
}

TEST(task1, test2) {
  std::stringstream strs;
  Automata* automata = new Automata(strs);
  automata->on();
  ASSERT_EQ(STATES::WAIT, automata->getState());
  EXPECT_EQ(strs.str(), "WAIT\n");
}

TEST(task1, test3) {
  std::stringstream strs;
  Automata* automata = new Automata(strs);
  automata->on();
  automata->off();
  ASSERT_EQ(STATES::OFF, automata->getState());
  EXPECT_EQ(strs.str(), "OFF\n");
}

TEST(task1, test4) {
  std::stringstream strs;
  Automata* automata = new Automata(strs);
  automata->on();
  automata->coin(100);
  ASSERT_EQ(STATES::ACCEPT, automata->getState());
  EXPECT_EQ(strs.str(), "ACCEPT\n");
}

TEST(task1, test5) {
  std::stringstream strs;
  Automata* automata = new Automata(strs);
  automata->on();
  automata->coin(50);
  automata->coin(30);
  ASSERT_EQ(STATES::ACCEPT, automata->getState());
  EXPECT_EQ(strs.str(), "ACCEPT\n");
}

TEST(task1, test6) {
  std::stringstream strs;
  Automata* automata = new Automata(strs);
  automata->on();
  ASSERT_THROW(automata->coin(0), std::runtime_error);
  ASSERT_THROW(automata->coin(-10), std::runtime_error);
}

TEST(task1, test7) {
  std::stringstream strs;
  Automata* automata = new Automata(strs);
  automata->on();
  auto menu = automata->getMenu();
  ASSERT_EQ(6, menu.size());
  ASSERT_EQ("Espresso", menu[0].itemName);
  ASSERT_EQ(35, menu[0].itemPrice);
  EXPECT_EQ(strs.str(),
            "Espresso: 35\nAmericano: 45\nCappuccino: 50\nHot chocolate: "
            "65\nRaf: 120\nTea: 20\n");
}

TEST(task1, test8) {
  std::stringstream strs;
  Automata* automata = new Automata(strs);
  auto menu = automata->getMenu();
  EXPECT_TRUE(menu.empty());
}

TEST(task1, test9) {
  std::stringstream strs;
  Automata* automata = new Automata(strs);
  automata->on();
  automata->coin(100);

  double change = automata->choice(0);

  ASSERT_EQ(65, change);
  ASSERT_EQ(STATES::WAIT, automata->getState());
  EXPECT_EQ(strs.str(), "Start cooking\nFinish\nOK, change: 65\nWAIT\n");
}

TEST(task1, test10) {
  std::stringstream strs;
  Automata* automata = new Automata(strs);
  automata->on();
  automata->coin(30);

  double change = automata->choice(0);

  ASSERT_EQ(30, change);
  ASSERT_EQ(STATES::WAIT, automata->getState());
  EXPECT_EQ(strs.str(), "NOT ENOUGHT MONEY, change: 30\nWAIT\n");
}

TEST(task1, test11) {
  std::stringstream strs;
  Automata* automata = new Automata(strs);
  automata->on();
  automata->coin(100);

  double change = automata->choice(99);

  ASSERT_EQ(100, change);
  ASSERT_EQ(STATES::WAIT, automata->getState());
  EXPECT_EQ(strs.str(), "INVALID ITEM, change: 100\nWAIT\n");
}

TEST(task1, test12) {
  std::stringstream strs;
  Automata* automata = new Automata(strs);
  automata->on();

  double change = automata->choice(0);

  ASSERT_EQ(0, change);
  EXPECT_EQ(strs.str(), "INACCESSIBLE, change: 0\n");
}

TEST(task1, test13) {
  std::stringstream strs;
  Automata* automata = new Automata(strs);
  automata->on();
  automata->coin(150);

  double change = automata->cancel();
  ASSERT_EQ(150, change);
  ASSERT_EQ(STATES::WAIT, automata->getState());
  EXPECT_EQ(strs.str(), "WAIT\n");
}