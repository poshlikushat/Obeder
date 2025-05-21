//
// Created by Куимов Михаил on 08.05.2025.
//

#include "../include/Obeder/Ledger.h"
#include "../include/Obeder/Parser.h"

void Ledger::addRecord(const Lunch& lunch) {
  records.push_back(lunch);
}

void Ledger::loadFromFile(const std::string& filename) {
  const auto lunches = Parser::parse(filename);
  records.insert(records.end(), lunches.begin(), lunches.end());
}

std::unordered_map<std::string, int> Ledger::getBalance(const std::time_t start, const std::time_t end) const {
  std::unordered_map<std::string, int> balance;
  balance.reserve(records.size());
  for (const auto&[ts, user_id, amount] : records) {
    if (ts >= start && ts <= end) {
      balance[user_id] += amount;
    }
  }
  return balance;
}