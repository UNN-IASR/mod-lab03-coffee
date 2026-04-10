// Copyright 2024 GHA Test Team

#include "Automata.h"
#include <iostream>
#include <stdexcept>

Automata::Automata(const std::vector<std::string>& menuList,
                   const std::vector<double>& priceList)
    : cash(0.0), menu(menuList), prices(priceList),
      state(STATES::OFF), selectedDrink(-1) {
    if (menuList.size() != priceList.size()) {
        throw std::invalid_argument(
            "Размеры массивов меню и цен не совпадают");
    }
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        std::cout << "[on] Автомат включён. Ожидание.\n";
    } else {
        std::cout << "[on] Автомат уже включён.\n";
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        std::cout << "[off] Автомат выключен.\n";
    } else {
        std::cout << "[off] Нельзя выключить автомат в текущем состоянии.\n";
    }
}

void Automata::coin(double amount) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        if (amount <= 0) {
            std::cout << "[coin] Некорректная сумма.\n";
            return;
        }
        cash += amount;
        state = STATES::ACCEPT;
        std::cout << "[coin] Внесено: " << amount
                  << " руб. Итого: " << cash << " руб.\n";
    } else {
        std::cout << "[coin] Нельзя вносить деньги в текущем состоянии.\n";
    }
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        std::cout << "[cancel] Возврат " << cash << " руб. Сеанс отменён.\n";
        cash = 0.0;
        selectedDrink = -1;
        state = STATES::WAIT;
    } else {
        std::cout << "[cancel] Отмена недоступна в текущем состоянии.\n";
    }
}

void Automata::choice(int drinkIndex) {
    if (state == STATES::ACCEPT) {
        if (drinkIndex < 0 ||
            drinkIndex >= static_cast<int>(menu.size())) {
            std::cout << "[choice] Неверный номер напитка.\n";
            return;
        }
        selectedDrink = drinkIndex;
        state = STATES::CHECK;
        std::cout << "[choice] Выбран напиток: " << menu[drinkIndex]
                  << " (" << prices[drinkIndex] << " руб.)\n";
    } else {
        std::cout << "[choice] Выбор недоступен в текущем состоянии.\n";
    }
}

void Automata::check() {
    if (state == STATES::CHECK) {
        if (cash >= prices[selectedDrink]) {
            std::cout << "[check] Сумма достаточна. Начинаем приготовление.\n";
            cook();
        } else {
            double deficit = prices[selectedDrink] - cash;
            std::cout << "[check] Недостаточно средств. "
                      << "Внесите ещё " << deficit << " руб.\n";
            state = STATES::ACCEPT;
            selectedDrink = -1;
        }
    } else {
        std::cout << "[check] Проверка недоступна в текущем состоянии.\n";
    }
}

void Automata::cook() {
    if (state == STATES::CHECK) {
        state = STATES::COOK;
        std::cout << "[cook] Готовится: " << menu[selectedDrink] << "...\n";
        std::cout << "[cook] Напиток готов! Заберите стакан.\n";
        finish();
    } else {
        std::cout << "[cook] Приготовление недоступно в текущем состоянии.\n";
    }
}

void Automata::finish() {
    if (state == STATES::COOK) {
        double change = cash - prices[selectedDrink];
        if (change > 0) {
            std::cout << "[finish] Сдача: " << change << " руб.\n";
        }
        cash = 0.0;
        selectedDrink = -1;
        state = STATES::WAIT;
        std::cout << "[finish] Обслуживание завершено. Ожидание.\n";
    } else {
        std::cout << "[finish] Завершение недоступно в текущем состоянии.\n";
    }
}

std::vector<std::string> Automata::getMenu() const {
    return menu;
}

std::vector<double> Automata::getPrices() const {
    return prices;
}

STATES Automata::getState() const {
    return state;
}

double Automata::getCash() const {
    return cash;
}

int Automata::getSelectedDrink() const {
    return selectedDrink;
}
