//
// Created by bart on 6-4-19.
//

#include "../api/Transaction.h"
#include <gtest/gtest.h>

TEST(Transaction, getIndex) {
    int index = 0;
    Transaction t(index, 1, "", "", 0, 0, 0, "Test transaction" ,"ACC");
    ASSERT_EQ(index, t.getIndex());
}