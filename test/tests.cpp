#include "/include/Automata.h"
#include <cassert>
#include <iostream>

// 1. OFF при создании
void test_initial_state() {
    Automata a;
    assert(a.getState() == OFF);
}

// 2. ON()
void test_on() {
    Automata a;
    a.on();
    assert(a.getState() == WAITING_FOR_COIN);
}

// 3. OFF()
void test_off() {
    Automata a;
    a.on();
    a.off();
    assert(a.getState() == OFF);
}

// 4. coin()
void test_coin() {
    Automata a;
    a.on();
    a.coin(2.0);
    assert(a.getCash() == 2.0);
}

// 5. getMenu()
void test_get_menu() {
    Automata a;
    std::string menu = a.getMenu();

    assert(menu.find("Tea") != std::string::npos);
    assert(menu.find("Coffee") != std::string::npos);
}

// 6. check() false
void test_check_false() {
    Automata a;
    a.on();
    a.coin(1.0);
    assert(a.check(1) == false);
}

// 7. check() true
void test_check_true() {
    Automata a;
    a.on();
    a.coin(5.0);
    assert(a.check(1) == true);
}

// 8. choice()
void test_choice_success() {
    Automata a;
    a.on();
    a.coin(5.0);
    a.choice(1);
    assert(a.getState() == FINISHED);
}

// 9. finish()
void test_finish() {
    Automata a;
    a.on();
    a.coin(5.0);
    a.choice(1);
    a.finish();

    assert(a.getState() == WAITING_FOR_COIN);
    assert(a.getCash() == 0);
}

// 10. cancel()
void test_cancel() {
    Automata a;
    a.on();
    a.coin(3.0);
    a.cancel();

    assert(a.getCash() == 0);
    assert(a.getState() == WAITING_FOR_COIN);
}

// 11. choice без денег
void test_choice_fail() {
    Automata a;
    a.on();
    a.coin(0.5);
    a.choice(1);

    assert(a.getState() == WAITING_FOR_COIN);
}

int main() {
    test_initial_state();
    test_on();
    test_off();
    test_coin();
    test_get_menu();
    test_check_false();
    test_check_true();
    test_choice_success();
    test_finish();
    test_cancel();
    test_choice_fail();

    std::cout << "ALL TESTS PASSED\n";
}
