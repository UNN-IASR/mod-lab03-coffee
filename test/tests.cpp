// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(test1, waitState) {
      std::string menu[5] = {
        "black tea",
        "green tea",
        "cappuccino",
        "latte",
        "hot chocolate"
     };
      int prices[5] = { 90, 90, 120, 130, 100 };
      Automata a1(menu, prices);
      a1.on();
      a1.coin(130);
      a1.choice(3);
      STATES result = a1.getState();
      EXPECT_EQ(WAIT, result);
}

TEST(test2, offState) {
      std::string menu[5] = {
        "black tea",
        "green tea",
        "cappuccino",
        "latte",
        "hot chocolate"
     };
      int prices[5] = { 90, 90, 120, 130, 100 };
      Automata a1(menu, prices);
      a1.on();
      a1.off();
      STATES result = a1.getState();
      EXPECT_EQ(OFF, result);
}

TEST(test3, acceptState) {
      std::string menu[5] = {
        "black tea",
        "green tea",
        "cappuccino",
        "latte",
        "hot chocolate"
     };
      int prices[5] = { 90, 90, 120, 130, 100 };
      Automata a1(menu, prices);
      a1.on();
      a1.coin(10);
      STATES result = a1.getState();
      EXPECT_EQ(ACCEPT, result);
}

TEST(test4, cancel) {
      std::string menu[5] = {
        "black tea",
        "green tea",
        "cappuccino",
        "latte",
        "hot chocolate"
     };
      int prices[5] = { 90, 90, 120, 130, 100 };
      Automata a1(menu, prices);
      a1.on();
      a1.coin(10);
      a1.cancel();
      STATES result = a1.getState();
      EXPECT_EQ(WAIT, result);
}

TEST(test5, notEnoughMoney) {
      std::string menu[5] = {
        "black tea",
        "green tea",
        "cappuccino",
        "latte",
        "hot chocolate"
     };
      int prices[5] = { 90, 90, 120, 130, 100 };
      Automata a1(menu, prices);
      a1.on();
      a1.coin(10);
      a1.choice(2);
      STATES result = a1.getState();
      EXPECT_EQ(ACCEPT, result);
}
