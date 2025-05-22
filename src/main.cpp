#include "../include/Obeder/Calculator.h"
#include "../include/Obeder/Ledger.h"
#include <iostream>
#include <limits>

int main() {
  const std::string filename = "../input/data.txt";
  Ledger ledger;
  ledger.loadFromFile(filename);

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