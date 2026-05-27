// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"

TEST(Testmach, TurnOnFromOff) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(Testmach, InitialCashIsZero) {
    Automata a;
    EXPECT_DOUBLE_EQ(a.getCash(), 0.0);
}

TEST(Testmach, InvalidChoiceIgnored) {
    Automata a;
    a.on();
    a.coin(100);
    EXPECT_FALSE(a.choice(99));
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(Testmach, CancelDuringAcceptResetsCash) {
    Automata a;
    a.on();
    a.coin(150);
    a.cancel();
    EXPECT_DOUBLE_EQ(a.getCash(), 0.0);
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(Testmach, EnoughMoneyForCoffee) {
    Automata a;
    a.on();
    a.coin(80);
    a.choice(2);
    EXPECT_TRUE(a.check());
}

TEST(Testmach, PrepareCappuccino) {
    Automata a;
    a.on();
    a.coin(120);
    a.choice(3);
    a.cook();
    EXPECT_EQ(a.getState(), COOK);
}

TEST(Testmach, FinishPurchaseGivesChange) {
    Automata a;
    a.on();
    a.coin(200);
    a.choice(5);
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), WAIT);
    EXPECT_DOUBLE_EQ(a.getCash(), 0.0);
}

TEST(Testmach, OffStateInitially) {
    Automata a;
    EXPECT_EQ(a.getState(), OFF);
}

TEST(Testmach, NegativeCoinDoesNothing) {
    Automata a;
    a.on();
    a.coin(-10);
    EXPECT_EQ(a.getState(), WAIT);
    EXPECT_DOUBLE_EQ(a.getCash(), 0.0);
}

TEST(Testmach, ChoiceWithoutMoneyStaysInWait) {
    Automata a;
    a.on();
    a.choice(2);
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(Testmach, CancelDuringCheck) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
    EXPECT_DOUBLE_EQ(a.getCash(), 0.0);
}

TEST(Testmach, CookWithoutCheckStaysInAccept) {
    Automata a;
    a.on();
    a.coin(60);
    a.cook();
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(Testmach, MenuContainsHotChocolate) {
    Automata a;
    a.on();
    std::string m = a.getMenu();
    EXPECT_NE(m.find("Горячий шоколад"), std::string::npos);
}

TEST(Testmach, NotEnoughForCoffee) {
    Automata a;
    a.on();
    a.coin(70);
    a.choice(2);
    EXPECT_FALSE(a.check());
}

TEST(Testmach, TurnOffWhenWait) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), OFF);
}

TEST(Testmach, FirstCoinMovesToAccept) {
    Automata a;
    a.on();
    a.coin(25);
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(Testmach, FinishWithoutCookingDoesNothing) {
    Automata a;
    a.on();
    a.finish();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(Testmach, ValidChoiceGoesToCheck) {
    Automata a;
    a.on();
    a.coin(150);
    a.choice(6);
    EXPECT_EQ(a.getState(), CHECK);
}

TEST(Testmach, MenuWhenOffShowsMessage) {
    Automata a;
    std::string m = a.getMenu();
    EXPECT_NE(m.find("выключен"), std::string::npos);
}
