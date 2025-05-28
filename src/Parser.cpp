//
// Created by Куимов Михаил on 08.05.2025.
//

#include "../include/Obeder/Parser.h"

#include <fstream>
#include <sstream>

std::vector<Lunch> Parser::parse(std::istream& in) {
  std::vector<Lunch> lunches;
  std::string line;

  while (std::getline(in, line)) {
    if (line.empty()) continue;
    std::istringstream iss(line);

    Lunch lunch;
    if (!(iss >> lunch.ts >> lunch.user_id >> lunch.amount)) {
      throw std::runtime_error("Failed to parse line: " + line);
    }
    lunches.push_back(lunch);
  }
  return lunches;
}
