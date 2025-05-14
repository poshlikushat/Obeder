//
// Created by Куимов Михаил on 08.05.2025.
//

#include "../include/Obeder/Ledger.h"
#include "../include/Obeder/Parser.h"

void Ledger::addRecords(const std::vector<Lunch>& recs) {
  records.insert(records.end(), recs.begin(), recs.end());
}

void Ledger::loadFromFile(const std::string& filename) {
  const auto lunches = Parser::parse(filename);
  addRecords(lunches);
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