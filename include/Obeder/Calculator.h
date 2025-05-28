//
// Created by Куимов Михаил on 08.05.2025.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <map>
#include <vector>
#include <string>
#include <unordered_map>

struct Debt {
  std::string from;
  std::string to;
  double amount;
};

class Calculator final {
  static void calculate(std::vector<Debt>& result, std::multimap<double, std::string> bal_mp);
public:
  static std::vector<Debt> settle(const std::unordered_map<std::string, double>& balances);
};



#endif //CALCULATOR_H
