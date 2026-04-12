// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
#include <cassert>
#include <sstream>

void test1() { Automata a; assert(a.getState() == STATES::OFF); }
void test2() { Automata a; a.on(); assert(a.getState() == STATES::WAIT); }
void test3() { Automata a; a.on(); a.off(); assert(a.getState() == STATES::OFF); }
void test4() { Automata a; a.on(); a.coin(10); assert(a.getState() == STATES::ACCEPT); }
void test5() { Automata a; a.on(); a.coin(20); a.cancel(); assert(a.getState() == STATES::WAIT); }
void test6() { Automata a; a.on(); a.choice(0); assert(a.getState() == STATES::WAIT); }
void test7() { Automata a; a.on(); a.coin(30); a.choice(0); assert(a.getState() == STATES::CHECK); }
void test8() { Automata a; a.on(); a.coin(100); a.choice(0); a.check(); assert(a.getState() == STATES::COOK); }
void test9() { Automata a; a.on(); a.coin(5); a.choice(0); a.check(); a.cancel(); assert(a.getState() == STATES::WAIT); }
void test10() { Automata a; a.on(); a.coin(50); a.choice(0); a.check(); a.cook(); a.finish(); assert(a.getState() == STATES::WAIT); }
int main() { test1(); test2(); test3(); test4(); test5(); test6(); test7(); test8(); test9(); test10(); }