//
// Created by Куимов Михаил on 08.05.2025.
//

#ifndef LEDGER_H
#define LEDGER_H
#include <string>
#include <vector>
#include <unordered_map>
#include "Parser.h"


class Ledger final {
  std::vector<Lunch> records;
public:
  void addRecord(const Lunch& lunch);
  void loadFromFile(const std::string& filename);
  [[nodiscard]] std::unordered_map<std::string, double> getBalance(std::time_t start, std::time_t end) const;
};


#endif //LEDGER_H
