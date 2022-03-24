// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(TEST1, incorrectly_action) {
    Automata anAutomat;

    try {
        anAutomat.on();
    }
    catch(std::logic_error& err) {
        ASSERT_STREQ("The machine has already started.", err.what());
    }
}

TEST(TEST2, incorrectly_action) {
    Automata anAutomat;

    try {
        anAutomat.off();
    }
    catch(std::logic_error& err) {
        ASSERT_STREQ("Unsafe shutdown has aborted.", err.what());
    }
}

TEST(TEST3, incorrectly_action) {
    Automata anAutomat;

    try {
        anAutomat.coin(121);
    }
    catch(std::logic_error& err) {
        ASSERT_STREQ("It's not the time to put money in.", err.what());
    }
}

TEST(TEST4, incorrectly_action) {
    Automata anAutomat;

    try {
        anAutomat.cancel();
    }
    catch(std::logic_error& err) {
        ASSERT_STREQ("The operation cannot be canceled."
        , err.what());
    }
}

TEST(TEST5, incorrectly_action) {
    Automata anAutomat;

    try {
        anAutomat.choice(4);
    }
    catch(std::logic_error& err) {
        ASSERT_STREQ("The operation cannot be canceled."
        , err.what());
    }
}

TEST(TEST6, incorrectly_action) {
    Automata anAutomat;

    try {
        anAutomat.check();
    }
    catch(std::logic_error& err) {
        ASSERT_STREQ("Verification is not possible..", err.what());
    }
}

TEST(TEST7, incorrectly_action) {
    Automata anAutomat;

    try {
        anAutomat.cook();
    }
    catch(std::logic_error& err) {
        ASSERT_STREQ("This operation is not possible at this stage..."
        , err.what());
    }
}

TEST(TEST8, incorrectly_action) {
    Automata anAutomat;

    try {
        anAutomat.finish();
    }
    catch(std::logic_error& err) {
        ASSERT_STREQ("This operation is not possible at this stage..."
        , err.what());
    }
}

TEST(TEST9, incorrectly_action) {
    Automata anAutomat;
    anAutomat.on();

    EXPECT_EQ(1, anAutomat.getState());
}

TEST(TEST10, correctly_action) {
    Automata anAutomat;
    anAutomat.on();
    anAutomat.coin(120);

    EXPECT_EQ(2, anAutomat.getState());
}

TEST(TEST11, correctly_action) {
    Automata anAutomat;
    anAutomat.on();
    anAutomat.coin(120);
    anAutomat.choice(4);

    EXPECT_EQ(3, anAutomat.getState());
}

TEST(TEST12, correctly_action) {
    Automata anAutomat;
    anAutomat.on();
    anAutomat.coin(120);
    anAutomat.choice(4);
    anAutomat.cook();

    EXPECT_EQ(4, anAutomat.getState());
}

TEST(TEST13, correctly_action) {
    Automata anAutomat;
    anAutomat.on();
    anAutomat.coin(120);
    anAutomat.choice(4);
    anAutomat.cook();
    anAutomat.finish();

    EXPECT_EQ(1, anAutomat.getState());
}

TEST(TEST14, correctly_action) {
    Automata anAutomat;

    EXPECT_EQ(0, anAutomat.getState());
}
