// Copyright 2022 GHA Test Team
#include "Automata.h"
#include <iostream>
#include <thread>
#include <chrono>

Automata::Automata()
  : cash(0), selectedItem(-1), state(STATES::OFF) {
  menu   = {"Кофе", "Чай", "Молоко", "Какао"};
  prices = {50,     30,    40,       45};
}

void Automata::on() {
  if (state == STATES::OFF) {
    state = STATES::WAIT;
    std::cout << "[on] Автомат включён. Состояние: WAIT\n";
  }
}

void Automata::off() {
  if (state == STATES::WAIT) {
    state = STATES::OFF;
    std::cout << "[off] Автомат выключён. Состояние: OFF\n";
  }
}

void Automata::coin(int amount) {
  if (state == STATES::WAIT || state == STATES::ACCEPT) {
    cash += amount;
    state = STATES::ACCEPT;
    std::cout << "[coin] Внесено: " << amount
              << " руб. Итого: " << cash
              << " руб. Состояние: ACCEPT\n";
  }
}

void Automata::cancel() {
  if (state == STATES::WAIT || state == STATES::ACCEPT) {
    if (cash > 0) {
      std::cout << "[cancel] Возврат " << cash << " руб.\n";
      cash = 0;
    }
    selectedItem = -1;
    state = STATES::WAIT;
    std::cout << "[cancel] Отмена. Состояние: WAIT\n";
  }
}

void Automata::choice(int item) {
  if (state == STATES::ACCEPT) {
    if (item >= 0 && item < static_cast<int>(menu.size())) {
      selectedItem = item;
      state = STATES::CHECK;
      std::cout << "[choice] Выбран: " << menu[item]
                << " (" << prices[item] << " руб.)\n";
    } else {
      std::cout << "[choice] Неверный номер позиции.\n";
    }
  }
}

void Automata::check() {
  if (state == STATES::CHECK) {
    if (selectedItem >= 0 && cash >= prices[selectedItem]) {
      std::cout << "[check] Средств достаточно.\n";
      cook();
    } else {
      int need = (selectedItem >= 0)
        ? prices[selectedItem] - cash : 0;
      std::cout << "[check] Недостаточно. Нужно ещё: "
                << need << " руб.\n";
      state = STATES::ACCEPT;
    }
  }
}

void Automata::cook() {
  if (state == STATES::CHECK) {
    state = STATES::COOK;
    std::cout << "[cook] Готовлю " << menu[selectedItem] << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    finish();
  }
}

void Automata::finish() {
  if (state == STATES::COOK) {
    cash -= prices[selectedItem];
    std::cout << "[finish] " << menu[selectedItem]
              << " готов! Сдача: " << cash << " руб.\n";
    cash = 0;
    selectedItem = -1;
    state = STATES::WAIT;
    std::cout << "[finish] Состояние: WAIT\n";
  }
}

void Automata::getMenu() const {
  std::cout << "--- Меню ---\n";
  for (int i = 0; i < static_cast<int>(menu.size()); i++) {
    std::cout << i << ". " << menu[i]
              << " - " << prices[i] << " руб.\n";
  }
}

STATES Automata::getState() const {
  return state;
}

int Automata::getCash() const {
  return cash;
}

int Automata::getSelectedItem() const {
  return selectedItem;
}
