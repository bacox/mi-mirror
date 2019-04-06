//
// Created by bart on 6-4-19.
//

#ifndef MONEY_INSIGHT_TRANSACTION_H
#define MONEY_INSIGHT_TRANSACTION_H


#include <string>

class transaction {
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

public:

};


#endif //MONEY_INSIGHT_TRANSACTION_H
