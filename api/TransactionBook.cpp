//
// Created by bart on 6-4-19.
//

#include "TransactionBook.h"

int TransactionBook::size() const {
    return (int) transactions.size();
}

bool TransactionBook::addTransaction(Transaction t) {
    if(hasIndex(t.getIndex()))
        return false;
    transactions.push_back(t);
    return true;
}

bool TransactionBook::hasIndex(int index) {
    return false;
}

std::ostream &operator<<(std::ostream &os, const TransactionBook &book) {
    os << "transactions: [" << book.size() << "]";
    for(Transaction t : book.transactions)
    {
        os << std::endl << "> " << t;
    }
    return os;
}
