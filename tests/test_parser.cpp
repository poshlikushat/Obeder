#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include <cstdio>
#include "../include/Obeder/IOHandler.h"

TEST(ParserTest, ParsesFromStringStream) {
  const std::string input =
      "1623074400 user1 12.5\n"
      "1623078000 user2 15.0\n"
      "1623081600 user3 20.75";
  std::istringstream iss(input);
  const auto lunches = IOHandler::parse(iss);

  ASSERT_EQ(lunches.size(), 3);
  EXPECT_EQ(lunches[0].ts, 1623074400);
  EXPECT_EQ(lunches[0].user_id, "user1");
  EXPECT_DOUBLE_EQ(lunches[0].amount, 12.5);
  EXPECT_EQ(lunches[2].user_id, "user3");
  EXPECT_DOUBLE_EQ(lunches[2].amount, 20.75);
}

TEST(ParserTest, ParsesFromFile) {
  auto filename = "test_data.txt";
  std::ofstream ofs(filename);
  ASSERT_TRUE(ofs.is_open());
  ofs << "1000000000 alice 5.0\n";
  ofs << "1000003600 bob 7.25\n";
  ofs.close();

  std::ifstream ifs(filename);
  ASSERT_TRUE(ifs.is_open());
  auto lunches = IOHandler::parse(ifs);
  ifs.close();

  std::remove(filename);

  ASSERT_EQ(lunches.size(), 2);
  EXPECT_EQ(lunches[0].user_id, "alice");
  EXPECT_DOUBLE_EQ(lunches[1].amount, 7.25);
}

TEST(ParserTest, ThrowsOnInvalidLine) {
  const std::string badInput = "not_a_timestamp baddata 123";
  std::istringstream iss(badInput);
  EXPECT_THROW(IOHandler::parse(iss), std::runtime_error);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
