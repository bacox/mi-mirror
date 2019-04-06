//
// Created by bart on 6-4-19.
//

#ifndef MONEY_INSIGHT_TRANSACTIONBOOK_H
#define MONEY_INSIGHT_TRANSACTIONBOOK_H


#include <vector>
#include <ostream>
#include "Transaction.h"

class TransactionBook {
private:
    std::vector<Transaction> transactions;

public:
    bool addTransaction(Transaction t);
    bool hasIndex(int index);

    int size() const;

    friend std::ostream &operator<<(std::ostream &os, const TransactionBook &book);
};


#endif //MONEY_INSIGHT_TRANSACTIONBOOK_H
