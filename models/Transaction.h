//
// Created by bart on 6-4-19.
//

#ifndef MONEY_INSIGHT_TRANSACTION_H
#define MONEY_INSIGHT_TRANSACTION_H


#include <string>
#include <ostream>
namespace Models {
    class Transaction {
    private:
        int index;
        int reservationDate;
        std::string receiverAccountReference;
        std::string senderAccountReference;
        std::string senderAccountName;
        double balanceBeforeTransaction;
        double mutationValue;
        int processDate;
        std::string description;
        std::string transactionCode;
        bool isAnnotated = false;
    public:
        int getReservationDate() const;

        const std::string &getReceiverAccountReference() const;

        const std::string &getSenderAccountReference() const;

        double getBalanceBeforeTransaction() const;

        double getMutationValue() const;

        int getProcessDate() const;

        const std::string &getDescription() const;

        const std::string &getTransactionCode() const;

        bool isIsAnnotated() const;

    public:
        Transaction(
                int index,
                int reservationDate,
                const std::string &receiverAccountReference,
                const std::string &senderAccountReference,
                double mutationBeforeTransaction,
                double mutationValue,
                int processDate,
                const std::string &description,
                const std::string &transactionCode
        );

        friend std::ostream &operator<<(std::ostream &os, const Models::Transaction &transaction1);

        int getIndex() const;
    };
}

#endif //MONEY_INSIGHT_TRANSACTION_H
