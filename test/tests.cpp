#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, CreateAutomata) {
    Automata a;
    SUCCEED();
}

TEST(AutomataTest, TurnOn) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), Automata::WAIT);
}

TEST(AutomataTest, TurnOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), Automata::OFF);
}

TEST(AutomataTest, InsertCoin) {
    Automata a;
    a.on();
    a.coin(50);
    EXPECT_EQ(a.getState(), Automata::ACCEPT);
}

TEST(AutomataTest, MultipleCoins) {
    Automata a;
    a.on();
    a.coin(30);
    a.coin(20);
    EXPECT_EQ(a.getState(), Automata::ACCEPT);
}

TEST(AutomataTest, ChoiceDrink) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    EXPECT_EQ(a.getState(), Automata::CHECK);
}

TEST(AutomataTest, EnoughMoney) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    a.check();
    EXPECT_EQ(a.getState(), Automata::COOK);
}

TEST(AutomataTest, NotEnoughMoney) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(1);
    a.check();
    EXPECT_EQ(a.getState(), Automata::WAIT);
}

TEST(AutomataTest, CookFinish) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    a.check();
    a.cook();
    EXPECT_EQ(a.getState(), Automata::WAIT);
}

TEST(AutomataTest, CancelOperation) {
    Automata a;
    a.on();
    a.coin(100);
    a.cancel();
    EXPECT_EQ(a.getState(), Automata::WAIT);
}

TEST(AutomataTest, ChoiceWithoutMoney) {
    Automata a;
    a.on();
    a.choice(1);
    EXPECT_EQ(a.getState(), Automata::WAIT);
}

TEST(AutomataTest, InvalidChoice) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(999); 
    EXPECT_EQ(a.getState(), Automata::ACCEPT);
}