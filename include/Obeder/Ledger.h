//
// Created by Куимов Михаил on 08.05.2025.
//

#ifndef LEDGER_H
#define LEDGER_H
#include <string>
#include <vector>
#include <unordered_map>
#include "IOHandler.h"


class Ledger final {
  std::vector<Lunch> records;
public:
  void addRecord(const Lunch& lunch);
  [[nodiscard]] std::unordered_map<std::string, double> getBalance(std::time_t start, std::time_t end) const;
};


#endif //LEDGER_H
