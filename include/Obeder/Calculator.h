//
// Created by Куимов Михаил on 08.05.2025.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <vector>
#include <string>
#include <unordered_map>

struct Debt {
  std::string from;
  std::string to;
  double amount;
};

class Calculator final {
public:
  static std::vector<Debt> settle(const std::unordered_map<std::string, double>& balances);
};



#endif //CALCULATOR_H
