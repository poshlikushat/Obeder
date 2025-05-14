//
// Created by Куимов Михаил on 08.05.2025.
//

#ifndef MODELS_H
#define MODELS_H
#include <string>
#include "Parser.h"


class LunchRecord {
  Lunch record;
  public:
  LunchRecord() = delete;
  ~LunchRecord() = default;
  LunchRecord operator=(const LunchRecord& other) = delete;
  LunchRecord(const LunchRecord& other) = delete;

  [[nodiscard]] std::time_t getTs() const;
  [[nodiscard]] std::string getUserId() const;
  [[nodiscard]] int getAmount() const;
};



#endif //MODELS_H
