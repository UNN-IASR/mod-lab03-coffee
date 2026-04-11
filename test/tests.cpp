// Copyright 2026 Senatorova Maria

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialState) {
    Automata a;
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, TurnOn) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, InsertCoin) {
    Automata a;
    a.on();
    a.coin(50);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

TEST(AutomataTest, ChoiceDrink) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);  // Выбираем Capuchino (индекс 1)
    EXPECT_EQ(a.getState(), STATES::CHECK);
}

TEST(AutomataTest, EnoughMoney) {
    Automata a;
    a.on();
    a.coin(200);
    a.choice(0);  // Latte стоит 80
    a.check();
    EXPECT_EQ(a.getState(), STATES::COOK);
}

TEST(AutomataTest, NotEnoughMoney) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(0);
    a.check();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, Cooking) {
    Automata a;
    a.on();
    a.coin(200);
    a.choice(0);
    a.check();
    a.cook();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, Cancel) {
    Automata a;
    a.on();
    a.coin(100);
    a.cancel();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, TurnOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, ChoiceWithoutMoney) {
    Automata a;
    a.on();
    a.choice(1);
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, MultipleCoins) {
    Automata a;
    a.on();
    a.coin(50);
    a.coin(50);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}
