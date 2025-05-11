//
// Created by Куимов Михаил on 08.05.2025.
//

#include "../include/Obeder/LunchRecord.h"

LunchRecord::LunchRecord(const std::time_t ts, const std::string &user_id, const int amount)
  : record(ts, user_id, amount) {}

std::time_t LunchRecord::getTs() const { return record.ts; }

std::string LunchRecord::getUserId() const { return record.user_id; }

int LunchRecord::getAmount() const { return record.amount; }