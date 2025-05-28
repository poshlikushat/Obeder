#include <fstream>

#include "../include/Obeder/Calculator.h"
#include "../include/Obeder/Ledger.h"
#include <iostream>
#include <limits>

int main() {
  // 1. Файл как строка
  const std::string filename = "../input/data.txt";

  // 2. Открываем ifstream
  std::ifstream file{filename};
  if (!file.is_open()) {
    std::cerr << "Не удалось открыть файл: " << filename << std::endl;
    return 1;
  }

  Ledger ledger;

  // 3. Парсим сразу из file
  auto lunches = Parser::parse(file);
  for (const auto& l : lunches) {
    ledger.addRecord(l);
  }

  const auto balances = ledger.getBalance(0, std::numeric_limits<std::time_t>::max());

  // ReSharper disable once CppTooWideScopeInitStatement
  const auto debts = Calculator::settle(balances);

  for (const auto&[from, to, amount] : debts) {
    std::cout
        << from << " -> " << to
        << "  -  " << amount << " руб. " << std::endl;
}

  return 0;
}