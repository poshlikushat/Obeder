// Parser.h
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <ctime>

struct Lunch {
  std::time_t ts;
  std::string user_id;
  double amount;
};

class Parser final {
public:
  static std::vector<Lunch> parse(std::istream& in);

  Parser() = delete;
};

#endif //PARSER_H
