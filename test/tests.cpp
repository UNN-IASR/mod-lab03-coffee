// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(BASE, sleep) {
    Automata coffee;

    EXPECT_EQ(0, coffee.getState());
}

TEST(BASE, turn_on) {
    Automata coffee;
    coffee.on();

    EXPECT_EQ(1, coffee.getState());
}

TEST(BASE, accept_money) {
    Automata coffee;
    coffee.on();
    coffee.coin(150);

    EXPECT_EQ(2, coffee.getState());
}

TEST(BASE, choice) {
    Automata coffee;
    coffee.on();
    coffee.coin(150);
    coffee.choice(1);

    EXPECT_EQ(3, coffee.getState());
}

TEST(BASE, check) {
    Automata coffee;
    coffee.on();
    coffee.coin(150);
    coffee.choice(1);
    coffee.check();

    EXPECT_EQ(3, coffee.getState());
}

TEST(BASE, cook) {
    Automata coffee;
    coffee.on();
    coffee.coin(150);
    coffee.choice(1);
    coffee.check();
    coffee.cook();

    EXPECT_EQ(4, coffee.getState());
}

TEST(BASE, finish) {
    Automata coffee;
    coffee.on();
    coffee.coin(150);
    coffee.choice(1);
    coffee.check();
    coffee.cook();
    coffee.finish();

    EXPECT_EQ(1, coffee.getState());
}

TEST(BASE, turn_off_1) {
    Automata coffee;
    coffee.on();
    coffee.coin(150);
    coffee.choice(1);
    coffee.check();
    coffee.cook();
    coffee.finish();
    coffee.off();

    EXPECT_EQ(0, coffee.getState());
}

TEST(BASE, turn_off_2) {
    Automata coffee;
    coffee.on();
    coffee.off();

    EXPECT_EQ(0, coffee.getState());
}

TEST(ERROR, unexp_on) {
    Automata coffee;
    coffee.on();
    try {
        coffee.on();
    } catch(const std::logic_error err) {
        ASSERT_STREQ("I'm already alive!", err.what());
    }
}

TEST(ERROR, unexp_off) {
    Automata coffee;
    try {
        coffee.off();
    } catch(const std::logic_error err) {
        ASSERT_STREQ("It's unsafe to off me now!", err.what());
    }
}

TEST(ERROR, unexp_money) {
    Automata coffee;
    try {
        coffee.coin(150);
    } catch(const std::logic_error err) {
        ASSERT_STREQ("I can't eat money now!", err.what());
    }
}

TEST(ERROR, incorr_choice) {
    Automata coffee;
    coffee.on();
    coffee.coin(150);
    try {
        coffee.choice(20);
    } catch(const std::logic_error err) {
        ASSERT_STREQ("I don't have that much food now!", err.what());
    }
}

TEST(ERROR, unexp_choice) {
    Automata coffee;
    try {
        coffee.choice(1);
    } catch(const std::logic_error err) {
        ASSERT_STREQ("You can't choice anything now!", err.what());
    }
}

TEST(ERROR, unexp_check) {
    Automata coffee;
    try {
        coffee.check();
    } catch(const std::logic_error err) {
        ASSERT_STREQ("It's nothing to check now!", err.what());
    }
}

TEST(ERROR, unexp_cancel) {
    Automata coffee;
    try {
        coffee.cancel();
    } catch(const std::logic_error err) {
        ASSERT_STREQ("Sorry you can't cancel it!", err.what());
    }
}

TEST(ERROR, unexp_cook) {
    Automata coffee;
    try {
        coffee.cook();
    } catch(const std::logic_error err) {
        ASSERT_STREQ("It's nothing to cook now!", err.what());
    }
}

TEST(ERROR, unexp_finish) {
    Automata coffee;
    try {
        coffee.finish();
    } catch(const std::logic_error err) {
        ASSERT_STREQ("It's nothing to finish now!", err.what());
    }
}

TEST(EXTRA, a_lot_of_money) {
    Automata coffee;
    coffee.on();
    coffee.coin(12);
    coffee.coin(23);
    coffee.coin(34);

    EXPECT_EQ(69, coffee.getCash());
}

TEST(EXTRA, need_more_money_1) {
    Automata coffee;
    coffee.on();
    coffee.coin(90);
    coffee.choice(1);

    EXPECT_EQ(false, coffee.check());
}

TEST(EXTRA, need_more_money_2) {
    Automata coffee;
    coffee.on();
    coffee.coin(90);
    coffee.choice(1);
    coffee.cancel();
    coffee.coin(150);
    coffee.choice(1);

    EXPECT_EQ(true, coffee.check());
}