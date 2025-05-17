//
// Created by Куимов Михаил on 08.05.2025.
//

#include "../include/Obeder/Calculator.h"
#include "../include/Obeder/Ledger.h"

std::vector<Debt> Calculator::settle(const std::unordered_map<std::string,int>& balances) {
  std::vector<std::pair<std::string, int>> debtors;
  std::vector<std::pair<std::string, int>> creditors;

  for (auto it : balances) {
    if (it.second < 0) debtors.emplace_back(it);
    else if (it.second > 0) creditors.emplace_back(it);
  }

  std::vector<Debt> result;
  result.reserve(std::max(debtors.size(), creditors.size()));

  size_t i = 0, j = 0;
  while (i < debtors.size() && j < creditors.size()) {
    auto& [debUser, debSum] = debtors[i];
    auto& [credUser, credSum] = creditors[j];

    const int transfer = std::min(credSum, -debSum);
    result.push_back(Debt{debUser, credUser, transfer});

    debSum += transfer;
    credSum -= transfer;

    if (debSum == 0) ++i;
    if (credSum == 0) ++j;
  }
  return result;
}