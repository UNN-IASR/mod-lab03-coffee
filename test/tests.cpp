// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include "Automata.h"

using std::invalid_argument;
using std::domain_error;

TEST(test1, incorrect_operation) {
    Automata ak47;
    ak47.state = CHECK;
    try {
        ak47.on();
    }
    catch (domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test2, incorrect_operation) {
    Automata ak47;
    ak47.state = CHECK;
    try {
        ak47.off();
    }
    catch (domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test3, incorrect_operation) {
    Automata ak47;
    ak47.state = OFF;
    try {
        ak47.coin(100);
    }
    catch (domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}
