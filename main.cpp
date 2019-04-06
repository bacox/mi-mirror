//
// Created by bart on 6-4-19.
//

#include <iostream>
#include "api/Transaction.h"
#include "api/TransactionBook.h"
#include <sqlite3.h>

int main(int argc, char *argv[])
{
    std::cout << "Hello Money Insight" << std::endl;

    Transaction t(0, 1, "bart", "cox", 0, 0, 0, "Test transaction" ,"ACC");
    Transaction t2(1, 1, "bart", "cox", 0, 0, 0, "Test transaction" ,"ACC");

    TransactionBook tb;

    tb.addTransaction(t);
    tb.addTransaction(t2);


    std::cout << tb << std::endl;
    return 0;
}
