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
                                                               balanceBeforeTransaction(mutationBeforeTransaction),
                                                               mutationValue(mutationValue), processDate(processDate),
                                                               description(description),
                                                               transactionCode(transactionCode) {}

std::ostream &operator<<(std::ostream &os, const Transaction &transaction1) {
    os << "index: " << transaction1.index << " reservationDate: " << transaction1.reservationDate
       << " receiverAccountReference: " << transaction1.receiverAccountReference << " senderAccountReference: "
       << transaction1.senderAccountReference << " balanceBeforeTransaction: "
       << transaction1.balanceBeforeTransaction << " mutationValue: " << transaction1.mutationValue << " processDate: "
       << transaction1.processDate << " description: " << transaction1.description << " transactionCode: "
       << transaction1.transactionCode;
    return os;
}

int Transaction::getIndex() const {
    return index;
}

int Transaction::getReservationDate() const {
    return reservationDate;
}

const std::string &Transaction::getReceiverAccountReference() const {
    return receiverAccountReference;
}

const std::string &Transaction::getSenderAccountReference() const {
    return senderAccountReference;
}

double Transaction::getBalanceBeforeTransaction() const {
    return balanceBeforeTransaction;
}

double Transaction::getMutationValue() const {
    return mutationValue;
}

int Transaction::getProcessDate() const {
    return processDate;
}

const std::string &Transaction::getDescription() const {
    return description;
}

const std::string &Transaction::getTransactionCode() const {
    return transactionCode;
}

bool Transaction::isIsAnnotated() const {
    return isAnnotated;
}
