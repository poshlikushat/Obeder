// demo_print.cpp
#include <iostream>
#include <vector>
#include "../include/Obeder/Calculator.h"

int main() {
  const std::vector<Debt> debts = {
    {"alice", "bob",  12.5},
    {"john",  "kate",  3.0}
  };

  // Выведет в консоль:
  Calculator::printInfo(std::cout, debts);

  return 0;
}
