// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(correct_transition, test1) {
  Automata a;
  a.on();
  STATES result = a.getState();
  EXPECT_EQ(WAIT, result);
}

TEST(correct_transition, test2) {
  Automata a;
  STATES result = a.getState();
  EXPECT_EQ(OFF, result);
}

TEST(correct_transition, test3) {
  Automata a;
  a.on();
  a.off();
  STATES result = a.getState();
  EXPECT_EQ(OFF, result);
}

TEST(correct_transition, test4) {
  Automata a;
  a.on();
  a.coin();
  STATES result = a.getState();
  EXPECT_EQ(ACCEPT, result);
}

TEST(correct_transition, test5) {
   Automata a;
   a.on();
   a.coin();
   a.coin();
   STATES result = a.getState();
   EXPECT_EQ(ACCEPT, result);
}

TEST(correct_transition, test6) {
   Automata a;
   std::vector <std::string> s = a.getMenu(); 
   std::stringstream ss(s);
   std::string name;
   std::getline(ss, name, ' ');
   int coins;
   std::string buff;
   std::getline(ss, buff, ' ');
   std::getline(ss, buff, ' ');
   coins = std::atoi(buff);
   a.on();
   for (int i = 0; i < coins; i++)
     a.coin();
   a.choice(name);
   STATES result = a.getState();
   EXPECT_EQ(WAIT, result);
}

TEST(correct_transition, test7) {
   Automata a;
   std::vector <std::string> s = a.getMenu(); 
   std::stringstream ss(s);
   std::string name;
   std::getline(ss, name, ' ');
   int coins;
   std::string buff;
   std::getline(ss, buff, ' ');
   std::getline(ss, buff, ' ');
   coins = std::atoi(buff);
   a.on();
   for (int i = 0; i < coins - 1; i++)
     a.coin();
   a.choice(name);
   STATES result = a.getState();
   EXPECT_EQ(CHECK, result);
}

TEST(correct_transition, test8) {
   Automata a;
   std::vector <std::string> s = a.getMenu(); 
   std::stringstream ss(s);
   std::string name;
   std::getline(ss, name, ' ');
   int coins;
   std::string buff;
   std::getline(ss, buff, ' ');
   std::getline(ss, buff, ' ');
   coins = std::atoi(buff);
   a.on();
   for (int i = 0; i < coins - 1; i++)
     a.coin();
   a.choice(name);
   a.cancel();
   STATES result = a.getState();
   EXPECT_EQ(WAIT, result);
}

TEST(correct_transition, test9) {
  Automata a;
  a.on();
  a.coin();
  a.cancel();
  STATES result = a.getState();
  EXPECT_EQ(ACCEPT, result);
}

TEST(correct_transition, test10) {
  Automata a;
  a.coin();
  STATES result = a.getState();
  EXPECT_EQ(OFF, result);
}
