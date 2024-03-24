// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public testing::Test {
protected:
	Automata vendingMachine;
};

TEST(AutomataTest, TurnOn) {
	Automata vendingMachine;
	vendingMachine.on();
	EXPECT_EQ(Wait, vendingMachine.GetState());
}

TEST(AutomataTest, TurnOff) {
	Automata vendingMachine;
	vendingMachine.on();
	vendingMachine.off();
	EXPECT_EQ(Off, vendingMachine.GetState());
}

TEST(AutomataTest, DrinkChoice) {
	Automata vendingMachine;
	vendingMachine.on();
	vendingMachine.coin(20);
	vendingMachine.choice(2);
	EXPECT_EQ(Check, vendingMachine.GetState());
}

TEST(AutomataTest, DrinkUnable) {
	Automata vendingMachine;
	vendingMachine.on();
	vendingMachine.coin(5);
	vendingMachine.choice(2);
	EXPECT_EQ(Check, vendingMachine.GetState());
}

TEST(AutomataTest, OperationCircle) {
	Automata vendingMachine;
	vendingMachine.on();
	vendingMachine.coin(5);
	vendingMachine.choice(2);
	vendingMachine.cancel();
	vendingMachine.coin(5);
	vendingMachine.coin(5);
	vendingMachine.choice(2);
	EXPECT_EQ(Check, vendingMachine.GetState());
}

TEST(AutomataTest, CookingTrue) {
	Automata vendingMachine;
	vendingMachine.on();
	vendingMachine.coin(20);
	vendingMachine.choice(2);
	vendingMachine.cook(2);
	EXPECT_EQ(Cook, vendingMachine.GetState());
}

TEST(AutomataTest, CookingFalse) {
	Automata vendingMachine;
	vendingMachine.on();
	vendingMachine.coin(10);
	vendingMachine.choice(2);
	vendingMachine.check(2);
	vendingMachine.cook(2);
	EXPECT_EQ(Check, vendingMachine.GetState());
}

TEST(AutomataTest, CookingCancel) {
	Automata vendingMachine;
	vendingMachine.on();
	vendingMachine.coin(20);
	vendingMachine.choice(2);
	vendingMachine.cook(2);
	vendingMachine.cancel();
	EXPECT_EQ(Cook, vendingMachine.GetState());
}

TEST(AutomataTest, CookingComplete) {
	Automata vendingMachine;
	vendingMachine.on();
	vendingMachine.coin(30);
	vendingMachine.choice(1);
	vendingMachine.cook(1);
	vendingMachine.finish();
	EXPECT_EQ(Wait, vendingMachine.GetState());
}

TEST(AutomataTest, MoneyAdding) {
	Automata vendingMachine;
	vendingMachine.on();
	vendingMachine.coin(20);
	vendingMachine.coin(10);
	vendingMachine.coin(20);
	EXPECT_EQ(Accept, vendingMachine.GetState());
}

TEST(AutomataTest, OnToOffOperation) {
	Automata vendingMachine;
	vendingMachine.on();
	vendingMachine.coin(5);
	vendingMachine.choice(2);
	vendingMachine.cancel();
	vendingMachine.coin(20);
	vendingMachine.choice(2);
	vendingMachine.check(2);
	vendingMachine.cook(2);
	vendingMachine.finish();
	vendingMachine.off();

	EXPECT_EQ(Off, vendingMachine.GetState());
}
