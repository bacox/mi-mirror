//
// Created by bart on 7-4-19.
//

#ifndef MONEY_INSIGHT_DATABASE_H
#define MONEY_INSIGHT_DATABASE_H


#include <sqlite3.h>
#include <string>
#include "../models/Transaction.h"


class Database {
private:
    sqlite3 * db;
    std::string dbFileName;
    bool connected = false;

    char *zErrMsg = 0;
    int rc;
    char *sql;

//    bool empty = true;

public:
    bool dbFileExists(std::string dbFile);
    void openDatabase(std::string dbFile);
    bool isConnected();
    void closeDataBase();

    bool insertTransaction(Models::Transaction t);
    bool updateTransaction(Models::Transaction t);
    bool deleteTransaction(Models::Transaction t);

    bool rowExists(std::string tableName, int id);

    int numberOfTransaction();

    int tableSize(std::string tableName);

    bool emptyDatabase(std::string dbFileName);

    bool tableExists(std::string tableName);

    bool emptyTable(std::string tableName);

    bool dropTable(std::string tableName);

    bool tableIsEmpty(std::string tableName);

    bool createTransactionTable();
    static const std::string TABLE_TRANSACTION;
private:
    bool fileExists(std::string pathToFile);

};

#endif //MONEY_INSIGHT_DATABASE_H
