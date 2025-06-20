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

class IOHandler final {
public:
  static std::vector<Lunch> parse(std::istream& in);

  IOHandler() = delete;
};

#endif //PARSER_H
