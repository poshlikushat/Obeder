//
// Created by Куимов Михаил on 08.05.2025.
//

#include "../include/Obeder/Calculator.h"
#include "../include/Obeder/Ledger.h"
#include <map>

std::vector<Debt> Calculator::settle(const std::unordered_map<std::string, double>& balances) {

  std::multimap<double, std::string> bal_mp;
  for (auto& [user, bal] : balances) {
    if (bal != 0)
      bal_mp.emplace(bal, user);
  }

  std::vector<Debt> result;
  result.reserve(balances.size());

  while (!bal_mp.empty()) {

    const auto low = bal_mp.begin();
    const auto high = std::prev(bal_mp.end());

    if (low->first >= 0 || high->first <= 0) {
      break;
    }

    const auto transfer = std::min(-low->first, high->first);
    const std::string debtor = low->second;
    const std::string creditor = high->second;
    result.push_back(Debt{debtor, creditor, transfer});

    auto newLow = low->first + transfer;
    auto newHigh = high->first - transfer;

    bal_mp.erase(low);
    bal_mp.erase(high);

    if (newLow  != 0) bal_mp.emplace(newLow,  debtor);
    if (newHigh != 0) bal_mp.emplace(newHigh, creditor);
  }
  return result;
}