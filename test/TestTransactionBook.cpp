//
// Created by bart on 6-4-19.
//

#include "../src/models/TransactionBook.h"
#include <gtest/gtest.h>

TEST(TransactionBook, AddTransaction) {

    Models::TransactionBook tb;

    int valueStart = tb.size();
    int index = 0;
    Models::Transaction t(index, 1, "", "", 0, 0, 0, "Test transaction" ,"ACC");

    tb.addTransaction(t);
    ASSERT_EQ(valueStart + 1, tb.size());

}