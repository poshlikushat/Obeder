//
// Created by Куимов Михаил on 08.05.2025.
//

#ifndef MODELS_H
#define MODELS_H
#include <ctime>
#include <string>
#include "Parser.h"


class LunchRecord {
  public:
  LunchRecord(std::time_t ts, const std::string &user_id, int amount);
  ~LunchRecord() = default;
  LunchRecord operator=(const LunchRecord& other) = delete;
  LunchRecord(const LunchRecord& other) = delete;

  [[nodiscard]] std::time_t getTs() const;
  [[nodiscard]] std::string getUserId() const;
  [[nodiscard]] int getAmount() const;
};



#endif //MODELS_H
