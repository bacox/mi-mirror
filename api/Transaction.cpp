//
// Created by bart on 6-4-19.
//

#include "Transaction.h"

Transaction::Transaction(int index, int reservationDate, const std::string &receiverAccountReference,
                         const std::string &senderAccountReference, double mutationBeforeTransaction,
                         double mutationValue, int processDate, const std::string &description,
                         const std::string &transactionCode) : index(index), reservationDate(reservationDate),
                                                               receiverAccountReference(receiverAccountReference),
                                                               senderAccountReference(senderAccountReference),
                                                               mutationBeforeTransaction(mutationBeforeTransaction),
                                                               mutationValue(mutationValue), processDate(processDate),
                                                               description(description),
                                                               transactionCode(transactionCode) {}

std::ostream &operator<<(std::ostream &os, const Transaction &transaction1) {
    os << "index: " << transaction1.index << " reservationDate: " << transaction1.reservationDate
       << " receiverAccountReference: " << transaction1.receiverAccountReference << " senderAccountReference: "
       << transaction1.senderAccountReference << " mutationBeforeTransaction: "
       << transaction1.mutationBeforeTransaction << " mutationValue: " << transaction1.mutationValue << " processDate: "
       << transaction1.processDate << " description: " << transaction1.description << " transactionCode: "
       << transaction1.transactionCode;
    return os;
}
