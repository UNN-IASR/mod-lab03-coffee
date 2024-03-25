#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public testing::Test {
protected:
    Automata Machine;
};

TEST(AutomataTest, test1) {
    Automata Machine;
    Machine.on();
    EXPECT_EQ(Wait, Machine.getState());
}

TEST(AutomataTest, test2) {
    Automata Machine;
    Machine.on();
    Machine.coin(30);
    EXPECT_EQ(Accept, Machine.getState());
}

TEST(AutomataTest, test3) {
    Automata Machine;
    Machine.on();
    Machine.off();
    EXPECT_EQ(Off, Machine.getState());
}

TEST(AutomataTest, test4) {
    Automata Machine;
    Machine.on();
    Machine.coin(30);
    Machine.choice("black tea");
    EXPECT_EQ(Check, Machine.getState());
}

TEST(AutomataTest, test5) {
    Automata Machine;
    Machine.on();
    Machine.coin(30);
    Machine.choice("black tea");
    EXPECT_EQ(Check, Machine.getState());
}

TEST(AutomataTest, test6) {
    Automata Machine;
    Machine.on();
    Machine.coin(30);
    Machine.choice("black tea");
    Machine.cancel();
    EXPECT_EQ(Check, Machine.getState());
}

TEST(AutomataTest, test7) {
    Automata Machine;
    Machine.on();
    Machine.coin(30);
    Machine.choice("black tea");
    Machine.cook("black tea");
    EXPECT_EQ(Cook, Machine.getState());
}

TEST(AutomataTest, test8) {
    Automata Machine;
    Machine.on();
    Machine.coin(30);
    Machine.choice("black tea");
    Machine.cook("black tea");
    Machine.finish("black tea");
    EXPECT_EQ(Wait, Machine.getState());
}

TEST(AutomataTest, test9) {
    Automata Machine;
    Machine.on();
    Machine.coin(10);
    Machine.choice("black tea");
    EXPECT_EQ(false, Machine.check());
}

TEST(AutomataTest, test10) {
    Automata Machine;
    Machine.on();
    Machine.coin(30);
    EXPECT_EQ("Mistake!", Machine.choice("nothing"););
}
