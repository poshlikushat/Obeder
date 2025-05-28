//
// Created by Куимов Михаил on 08.05.2025.
//

#include "../include/Obeder/Ledger.h"
#include "../include/Obeder/IOHandler.h"

void Ledger::addRecord(const Lunch& lunch) {
  records.push_back(lunch);
}

std::unordered_map<std::string, double> Ledger::getBalance(const std::time_t start, const std::time_t end) const {
  std::unordered_map<std::string, double> balance;
  balance.reserve(records.size());
  for (const auto&[ts, user_id, amount] : records) {
    if (ts >= start && ts <= end) {
      balance[user_id] += amount;
    }
  }
  return balance;
}