//
// Created by bart on 6-4-19.
//

#ifndef MONEY_INSIGHT_TRANSACTION_H
#define MONEY_INSIGHT_TRANSACTION_H


#include <string>
#include <ostream>

class Transaction {
private:
    int index;
    int reservationDate;
    std::string receiverAccountReference;
    std::string senderAccountReference;
    double mutationBeforeTransaction;
    double mutationValue;
    int processDate;
    std::string description;
    std::string transactionCode;
    bool isAnnotated = false;

public:
    Transaction(int index, int reservationDate, const std::string &receiverAccountReference,
                const std::string &senderAccountReference, double mutationBeforeTransaction, double mutationValue,
                int processDate, const std::string &description, const std::string &transactionCode);

    friend std::ostream &operator<<(std::ostream &os, const Transaction &transaction1);
};


#endif //MONEY_INSIGHT_TRANSACTION_H
