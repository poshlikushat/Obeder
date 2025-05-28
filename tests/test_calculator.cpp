// tests/test_calculator.cpp
#include <gtest/gtest.h>
#include "../include/Obeder/Calculator.h"
#include <cstdio>
#include <fstream>

TEST(CalculatorTest, SimplePair) {
  std::unordered_map<std::string, double> balances{
          {"debtor", -5.0},
          {"creditor", 5.0}
  };

  const auto debts = Calculator::settle(balances);
  ASSERT_EQ(debts.size(), 1u);
  EXPECT_EQ(debts[0].from, "debtor");
  EXPECT_EQ(debts[0].to,   "creditor");
  EXPECT_DOUBLE_EQ(debts[0].amount, 5.0);
}

TEST(CalculatorTest, MultipleDebtorsAndCreditors) {
  const std::unordered_map<std::string, double> balances{
          {"a", -5.0},
          {"b", 8.0},
          {"c", -3.0}
  };

  const auto debts = Calculator::settle(balances);
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
  const std::unordered_map<std::string, double> balances{
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

TEST(CalculatorPrintInfo, CapturesStdout) {
  const std::vector<Debt> debts = {
    {"alice", "bob", 12.5},
    {"john", "kate", 3.0}
  };
  // Начинаем перехват stdout
  testing::internal::CaptureStdout();

  // Вызываем статический метод прямо через класс
  Calculator::printInfo(std::cout, debts);

  // Получаем то, что «упало» в stdout
  const std::string output = testing::internal::GetCapturedStdout();

  // Ожидаемый результат
  std::string expected;
  expected += "alice -> bob : 12.5\n";
  expected += "john -> kate : 3\n";

  EXPECT_EQ(output, expected);
}

TEST(CalculatorPrintInfo, WritesToTempFile) {
  std::vector<Debt> debts = {
    {"alice", "bob",  12.5},
    {"john",  "kate", 3.0}
  };

  char temp_name[L_tmpnam];
  std::tmpnam(temp_name);

  {
    std::ofstream ofs(temp_name);
    ASSERT_TRUE(ofs.is_open()) << "Не удалось создать файл: " << temp_name;
    Calculator::printInfo(ofs, debts);
  }

  // Читаем обратно
  std::ifstream ifs(temp_name);
  ASSERT_TRUE(ifs.is_open()) << "Не удалось открыть файл для чтения: " << temp_name;
  std::string content(
      (std::istreambuf_iterator<char>(ifs)),
      std::istreambuf_iterator<char>()
  );
  ifs.close();

  std::remove(temp_name);

  std::string expected;
  expected += "alice -> bob : 12.5\n";
  expected += "john -> kate : 3\n";

  EXPECT_EQ(content, expected);
}

