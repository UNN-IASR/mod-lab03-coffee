// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

// 1. После создания автомат выключен
TEST(AutomataTest, InitialStateIsOff) {
    Automata a;
    EXPECT_EQ(a.getState(), STATES::OFF);
}

// 2. on() переводит из OFF в WAIT
TEST(AutomataTest, OnSwitchesToWait) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

// 3. off() переводит из WAIT в OFF
TEST(AutomataTest, OffSwitchesToOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), STATES::OFF);
}

// 4. on() не срабатывает, если автомат уже включён
TEST(AutomataTest, OnDoesNothingIfAlreadyOn) {
    Automata a;
    a.on();
    a.on();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

// 5. off() не срабатывает, если автомат выключен
TEST(AutomataTest, OffDoesNothingIfAlreadyOff) {
    Automata a;
    a.off();
    EXPECT_EQ(a.getState(), STATES::OFF);
}

// 6. coin() переводит в ACCEPT
TEST(AutomataTest, CoinSwitchesToAccept) {
    Automata a;
    a.on();
    a.coin(20);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

// 7. Несколько монет накапливаются и состояние остаётся ACCEPT
TEST(AutomataTest, MultipleCoinsStayAccept) {
    Automata a;
    a.on();
    a.coin(10);
    a.coin(20);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

// 8. Успешная покупка возвращает в WAIT
TEST(AutomataTest, SuccessfulPurchaseReturnsToWait) {
    Automata a;
    a.on();
    a.coin(30);   // Чай стоит 30
    a.choice(2);  // Выбор чая (индекс 2)
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

// 9. Недостаточно средств — остаётся в ACCEPT
TEST(AutomataTest, InsufficientFundsStaysAccept) {
    Automata a;
    a.on();
    a.coin(10);   // Кофе стоит 50, денег мало
    a.choice(1);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

// 10. cancel() из ACCEPT возвращает в WAIT
TEST(AutomataTest, CancelFromAcceptReturnsToWait) {
    Automata a;
    a.on();
    a.coin(50);
    a.cancel();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

// 11. coin() не работает, когда автомат выключен
TEST(AutomataTest, CoinIgnoredWhenOff) {
    Automata a;
    a.coin(50);
    EXPECT_EQ(a.getState(), STATES::OFF);
}

// 12. choice() с неверным номером не меняет состояние
TEST(AutomataTest, InvalidChoiceKeepsAcceptState) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(99);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

// 13. После отмены можно снова внести деньги
TEST(AutomataTest, CanInsertCoinsAfterCancel) {
    Automata a;
    a.on();
    a.coin(20);
    a.cancel();
    a.coin(50);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

// 14. Покупка самого дешёвого напитка (молоко, 20 руб.)
TEST(AutomataTest, BuyCheapestDrink) {
    Automata a;
    a.on();
    a.coin(20);
    a.choice(3);  // Молоко — 20 руб.
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

// 15. Покупка с избытком денег завершается успешно
TEST(AutomataTest, PurchaseWithExcessMoneySucceeds) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(4);  // Какао — 40 руб.
    EXPECT_EQ(a.getState(), STATES::WAIT);
}
