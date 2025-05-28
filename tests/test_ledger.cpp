// tests/test_ledger.cpp
#include <gtest/gtest.h>
#include "../include/Obeder/Ledger.h"

TEST(LedgerTest, SingleRecord) {
  Ledger ledger;
  const Lunch l1{1000, "alice", 12.5};
  ledger.addRecord(l1);

  auto bal = ledger.getBalance(0, 2000);
  ASSERT_EQ(bal.size(), 1u);
  EXPECT_DOUBLE_EQ(bal["alice"], 12.5);
}

TEST(LedgerTest, MultipleRecordsAndTimeFilter) {
  Ledger ledger;
  ledger.addRecord({100, "a", 5.0});
  ledger.addRecord({200, "b", 7.0});
  ledger.addRecord({300, "a", 3.0});
  // should ignore ts=50 and ts=400
  ledger.addRecord({50,  "c", 1.0});
  ledger.addRecord({400, "b", 2.0});

  auto bal_all = ledger.getBalance(0, std::numeric_limits<std::time_t>::max());
  EXPECT_DOUBLE_EQ(bal_all["a"], 8.0);
  EXPECT_DOUBLE_EQ(bal_all["b"], 9.0);
  EXPECT_DOUBLE_EQ(bal_all["c"], 1.0);

  auto bal_mid = ledger.getBalance(100, 300);
  ASSERT_EQ(bal_mid.size(), 2u);
  EXPECT_DOUBLE_EQ(bal_mid["a"], 8.0);
  EXPECT_DOUBLE_EQ(bal_mid["b"], 7.0);
}
