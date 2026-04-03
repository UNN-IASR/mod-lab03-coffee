// Copyright 2025 MaximLazarenko
#include <iostream>
#include "Automata.h"

int main() {
    Automata a;

    a.on();
    std::cout << "Состояние после включения: " << a.getState() << std::endl;

    a.coin(30);
    a.coin(30);
    std::cout << "Баланс: " << a.cash << std::endl;

    a.choice(0);
    std::cout << "Состояние после выбора: " << a.getState() << std::endl;

    if (a.check()) {
        a.cook();
        std::cout << "Состояние после приготовления: ";
        std::cout << a.getState() << std::endl;
        a.finish();
        std::cout << "Сдача: " << a.cash << std::endl;
        std::cout << "Состояние после завершения: ";
        std::cout << a.getState() << std::endl;
    } else {
        a.cancel();
        std::cout << "Недостаточно средств, отмена" << std::endl;
    }

    std::cout << std::endl;
    a.coin(10);
    a.choice(3);
    if (a.check()) {
        a.cook();
        a.finish();
    } else {
        a.cancel();
        std::cout << "Недостаточно средств, отмена. Возврат." << std::endl;
    }

    a.off();
    std::cout << "Состояние после выключения: " << a.getState() << std::endl;

    return 0;
}
