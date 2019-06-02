//
// Created by bart on 6-4-19.
//

#include "TransactionBook.h"

int Models::TransactionBook::size() const {
    return (int) transactions.size();
}

bool Models::TransactionBook::addTransaction(Transaction t) {
    if(hasIndex(t.getIndex()))
        return false;
    transactions.push_back(t);
    return true;
}

bool Models::TransactionBook::hasIndex(int index) {
    return false;
}

namespace Models {
    std::ostream &operator<<(std::ostream &os, const Models::TransactionBook &book) {
        os << "transactions: [" << book.size() << "]";
        for (Models::Transaction t : book.transactions) {
            os << std::endl << "> " << t;
        }
        return os;
    }
}
