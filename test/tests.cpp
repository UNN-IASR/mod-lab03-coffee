#include <gtest/gtest.h>
#include "Automata.h"

// 1. Проверка начального состояния
TEST(AutomataTest, InitialState) {
    Automata a;
    EXPECT_EQ(a.getState(), STATES::OFF);
}

// 2. Включение автомата
TEST(AutomataTest, TurnOn) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

// 3. Вставка денег
TEST(AutomataTest, InsertCoin) {
    Automata a;
    a.on();
    a.coin(50);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

// 4. Выбор напитка
TEST(AutomataTest, ChoiceDrink) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);  // Выбираем Capuchino (индекс 1)
    EXPECT_EQ(a.getState(), STATES::CHECK);
}

// 5. Достаточно денег → COOK
TEST(AutomataTest, EnoughMoney) {
    Automata a;
    a.on();
    a.coin(200);
    a.choice(0);  // Latte стоит 80
    a.check();
    EXPECT_EQ(a.getState(), STATES::COOK);
}

// 6. Недостаточно денег → WAIT
TEST(AutomataTest, NotEnoughMoney) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(0);  // Latte стоит 80 - недостаточно
    a.check();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

// 7. Приготовление возвращает в WAIT
TEST(AutomataTest, Cooking) {
    Automata a;
    a.on();
    a.coin(200);
    a.choice(0);
    a.check();
    a.cook();  // cook() вызывает finish() внутри, который переводит в WAIT
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

// 8. Отмена операции
TEST(AutomataTest, Cancel) {
    Automata a;
    a.on();
    a.coin(100);
    a.cancel();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

// 9. Выключение автомата
TEST(AutomataTest, TurnOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), STATES::OFF);
}

// 10. Нельзя выбрать напиток без денег
TEST(AutomataTest, ChoiceWithoutMoney) {
    Automata a;
    a.on();
    a.choice(1);  // Пытаемся выбрать без денег
    EXPECT_EQ(a.getState(), STATES::WAIT);  // Состояние не должно измениться
}


// 11. Повторное добавление денег
TEST(AutomataTest, MultipleCoins) {
    Automata a;
    a.on();
    a.coin(50);
    a.coin(50);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}