#include "Automata.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Automata coffeeMachine;
    cout << "\nДемонстрация работы автомата\n\n";
    cout << coffeeMachine.getMenu();
    cout << "\nПрограмма 1: Успешная покупка\n";
    coffeeMachine.on();
    coffeeMachine.coin(100);
    coffeeMachine.choice(2);
    cout << "\nПрограмма 2: Попытка купить без денег\n";
    coffeeMachine.on();
    coffeeMachine.choice(1);
    cout << "\nПрограмма 3: Недостаточно денег\n";
    coffeeMachine.on();
    coffeeMachine.coin(30);
    coffeeMachine.choice(1);
    cout << "\nПрограмма 4: Отмена операции\n";
    coffeeMachine.on();
    coffeeMachine.coin(200);
    coffeeMachine.cancel();
    coffeeMachine.choice(3);
    cout << "\nПрограммай 5: Добавление денег по частям\n";
    coffeeMachine.on();
    coffeeMachine.coin(30);
    coffeeMachine.coin(20);
    coffeeMachine.choice(1);
    cout << "\nКонец демонстрации\n";
    return 0;
}
