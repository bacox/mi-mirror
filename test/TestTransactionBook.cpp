//
// Created by bart on 6-4-19.
//

#include <gtest/gtest.h>
#include <models/TransactionBook.h>

TEST(TransactionBook, AddTransaction) {

    Models::TransactionBook tb;

    int valueStart = tb.size();
    int index = 0;
    Models::Transaction t(index, 1, "", "", 0, 0, 0, "Test transaction" ,"ACC");

    tb.addTransaction(t);
    ASSERT_EQ(valueStart + 1, tb.size());

}