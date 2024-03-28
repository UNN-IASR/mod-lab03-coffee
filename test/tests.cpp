// Copyright 2022 Yuriy Korshunov

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

    EXPECT_EQ(4, coffee.getState());
}

TEST(BASE, check) {
    Automata coffee;
    coffee.on();
    coffee.coin(150);
    coffee.choice(1);
    coffee.check();

    EXPECT_EQ(4, coffee.getState());
}

TEST(BASE, cook) {
    Automata coffee;
    coffee.on();
    coffee.coin(150);
    coffee.choice(1);
    coffee.check();
    coffee.cook();

    EXPECT_EQ(3, coffee.getState());
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
        ASSERT_STREQ("Already on", err.what());
    }
}

TEST(ERROR, unexp_off) {
    Automata coffee;
    try {
        coffee.off();
    } catch(const std::logic_error err) {
        ASSERT_STREQ("Unsafe to off now", err.what());
    }
}

TEST(ERROR, unexp_money) {
    Automata coffee;
    try {
        coffee.coin(150);
    } catch(const std::logic_error err) {
        ASSERT_STREQ("Can't get money now", err.what());
    }
}

TEST(ERROR, unexp_choice) {
    Automata coffee;
    try {
        coffee.choice(1);
    } catch(const std::logic_error err) {
        ASSERT_STREQ("Can't choice now", err.what());
    }
}

TEST(ERROR, unexp_check) {
    Automata coffee;
    try {
        coffee.check();
    } catch(const std::logic_error err) {
        ASSERT_STREQ("Nothing to check", err.what());
    }
}

TEST(ERROR, unexp_cancel) {
    Automata coffee;
    try {
        coffee.cancel();
    } catch(const std::logic_error err) {
        ASSERT_STREQ("Can't cancel now", err.what());
    }
}

TEST(ERROR, unexp_cook) {
    Automata coffee;
    try {
        coffee.cook();
    } catch(const std::logic_error err) {
        ASSERT_STREQ("Nothing to cook", err.what());
    }
}

TEST(ERROR, unexp_finish) {
    Automata coffee;
    try {
        coffee.finish();
    } catch(const std::logic_error err) {
        ASSERT_STREQ("Nothing to finish", err.what());
    }
}
