//
// Created by Куимов Михаил on 08.05.2025.
//

#include "../include/Obeder/Parser.h"

#include <fstream>
#include <sstream>

std::vector<Lunch> Parser::parse(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) throw std::runtime_error("Failed to open file: " + filename);
  std::vector<Lunch> lunches;
  std::string line;

  while (std::getline(file, line)) {
    if (line.empty()) continue;

    std::istringstream iss(line);  // Читает данные не из файла, а из строки в памяти
    Lunch lunch;
    if (!(iss >> lunch.ts >> lunch.user_id >> lunch.amount)) {
      throw std::runtime_error("Failed to parse line: " + line);
    }
    lunches.push_back(lunch);
  }
  return lunches;
}
