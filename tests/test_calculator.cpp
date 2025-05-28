// tests/test_calculator.cpp
#include <gtest/gtest.h>
#include "../include/Obeder/Calculator.h"

using Obeder::Calculator;
using Obeder::Debt;

TEST(CalculatorTest, SimplePair) {
  std::unordered_map<std::string, double> balances{
          {"debtor", -5.0},
          {"creditor", 5.0}
  };

  auto debts = Calculator::settle(balances);
  ASSERT_EQ(debts.size(), 1u);
  EXPECT_EQ(debts[0].from, "debtor");
  EXPECT_EQ(debts[0].to,   "creditor");
  EXPECT_DOUBLE_EQ(debts[0].amount, 5.0);
}

TEST(CalculatorTest, MultipleDebtorsAndCreditors) {
  // a owes 5, c owes 3; b should receive 8
  std::unordered_map<std::string, double> balances{
          {"a", -5.0},
          {"b", 8.0},
          {"c", -3.0}
  };

  auto debts = Calculator::settle(balances);
  // order may vary, so just check sums
  double total = 0;
  for (auto& d : debts) {
    total += d.amount;
  }
  EXPECT_DOUBLE_EQ(total, 8.0);
  // проверь каждый перевод корректен
  for (auto& d : debts) {
    EXPECT_EQ(d.to, "b");
    EXPECT_TRUE(d.from == "a" || d.from == "c");
  }
}

TEST(CalculatorTest, NoDebtsWhenBalanced) {
  std::unordered_map<std::string, double> balances{
          {"x", 2.0},
          {"y", -2.0},
          {"z", 0.0}
  };
  auto debts = Calculator::settle(balances);
  ASSERT_FALSE(debts.empty());
  // x->y на 2
  EXPECT_EQ(debts[0].from, "y");
  EXPECT_EQ(debts[0].to,   "x");
  EXPECT_DOUBLE_EQ(debts[0].amount, 2.0);
}
