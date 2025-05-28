#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include <cstdio>      // for std::remove
#include "../include/Obeder/Parser.h"

// Удобный алиас
using Obeder::Parser;

// Структура Lunch должна быть определена в ../include/Obeder/Ledger.h
struct Lunch {
  std::time_t ts;
  std::string user_id;
  double amount;
};

TEST(ParserTest, ParsesFromStringStream) {
  std::string input =
      "1623074400 user1 12.5\n"
      "1623078000 user2 15.0\n"
      "   \n"              // пустая строка пропускается
      "1623081600 user3 20.75";
  std::istringstream iss(input);
  auto lunches = Parser::parse(iss);

  ASSERT_EQ(lunches.size(), 3);
  EXPECT_EQ(lunches[0].ts, 1623074400);
  EXPECT_EQ(lunches[0].user_id, "user1");
  EXPECT_DOUBLE_EQ(lunches[0].amount, 12.5);
  EXPECT_EQ(lunches[2].user_id, "user3");
  EXPECT_DOUBLE_EQ(lunches[2].amount, 20.75);
}

TEST(ParserTest, ParsesFromFile) {
  const char* filename = "test_data.txt";
  // Создаём временный файл
  std::ofstream ofs(filename);
  ASSERT_TRUE(ofs.is_open());
  ofs << "1000000000 alice 5.0\n";
  ofs << "1000003600 bob 7.25\n";
  ofs.close();

  std::ifstream ifs(filename);
  ASSERT_TRUE(ifs.is_open());
  auto lunches = Parser::parse(ifs);
  ifs.close();

  // Удаляем временный файл
  std::remove(filename);

  ASSERT_EQ(lunches.size(), 2);
  EXPECT_EQ(lunches[0].user_id, "alice");
  EXPECT_DOUBLE_EQ(lunches[1].amount, 7.25);
}

TEST(ParserTest, ThrowsOnInvalidLine) {
  std::string badInput = "not_a_timestamp baddata 123";
  std::istringstream iss(badInput);
  EXPECT_THROW(Parser::parse(iss), std::runtime_error);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
