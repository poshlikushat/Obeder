#include "../include/Obeder/Calculator.h"
#include "../include/Obeder/Ledger.h"
#include <iostream>
#include <iomanip>
#include <limits>

int main() {
  const std::string filename = "../input/data.txt";
  // Загружаем все записи из data.txt
  Ledger ledger;
  ledger.loadFromFile(filename);

  // считаем балансы за весь период
  const auto balances = ledger.getBalance(0, std::numeric_limits<std::time_t>::max());

  // сводим долги
  const auto debts = Calculator::settle(balances);

  // печатаем результат
  for (const auto&[from, to, amount] : debts) {
    const int r = amount / 100;
    const int k = amount % 100;
    std::cout
        << from << " -> " << to
        << "  -  " << r << " р "
        << std::setw(2) << std::setfill('0') << k << " коп\n";
}

  return 0;
}