// Parser.h
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <ctime>
#include <vector>

struct Lunch {
  std::time_t ts;
  std::string user_id;
  int amount;
};

class Parser {
public:
  static std::vector<Lunch> parse(const std::string& filename);

  Parser() = delete;
  ~Parser() = delete;
  Parser(const Parser& other) = delete;
  Parser& operator=(const Parser& other) = delete;
};

#endif //PARSER_H
