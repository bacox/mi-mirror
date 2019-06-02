//
// Created by bart on 6-4-19.
//

#include "Transaction.h"

Models::Transaction::Transaction(int index, int reservationDate, const std::string &receiverAccountReference,
                         const std::string &senderAccountReference, double mutationBeforeTransaction,
                         double mutationValue, int processDate, const std::string &description,
                         const std::string &transactionCode) : index(index), reservationDate(reservationDate),
                                                               receiverAccountReference(receiverAccountReference),
                                                               senderAccountReference(senderAccountReference),
                                                               balanceBeforeTransaction(mutationBeforeTransaction),
                                                               mutationValue(mutationValue), processDate(processDate),
                                                               description(description),
                                                               transactionCode(transactionCode) {}
namespace Models {
    std::ostream &operator<<(std::ostream &os, const Models::Transaction &transaction1) {
        os << "index: " << transaction1.index << " reservationDate: " << transaction1.reservationDate
           << " receiverAccountReference: " << transaction1.receiverAccountReference << " senderAccountReference: "
           << transaction1.senderAccountReference << " balanceBeforeTransaction: "
           << transaction1.balanceBeforeTransaction << " mutationValue: " << transaction1.mutationValue
           << " processDate: "
           << transaction1.processDate << " description: " << transaction1.description << " transactionCode: "
           << transaction1.transactionCode;
        return os;
    }
}

int Models::Transaction::getIndex() const {
    return index;
}

int Models::Transaction::getReservationDate() const {
    return reservationDate;
}

const std::string &Models::Transaction::getReceiverAccountReference() const {
    return receiverAccountReference;
}

const std::string &Models::Transaction::getSenderAccountReference() const {
    return senderAccountReference;
}

double Models::Transaction::getBalanceBeforeTransaction() const {
    return balanceBeforeTransaction;
}

double Models::Transaction::getMutationValue() const {
    return mutationValue;
}

int Models::Transaction::getProcessDate() const {
    return processDate;
}

const std::string &Models::Transaction::getDescription() const {
    return description;
}

const std::string &Models::Transaction::getTransactionCode() const {
    return transactionCode;
}

bool Models::Transaction::isIsAnnotated() const {
    return isAnnotated;
}
