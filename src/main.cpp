#include <sstream>
#include <string>
#include <iostream>
#include "../include/Obeder/Parser.h"

int main() {
  const std::string filename = "../input/data.txt";
  std::vector<Lunch> lunches = Parser::parse(filename);
  std::cout << "Parsed lunches:\n";
  for (const auto& lunch : lunches) {
    std::cout << "Timestamp: " << lunch.ts << ", User ID: " << lunch.user_id << ", Amount: " << lunch.amount << "\n" << std::endl;
  }
}
