//
// Created by bart on 7-4-19.
//

#include <boost/filesystem/operations.hpp>
#include <iostream>
#include "Database.h"
const std::string Database::TABLE_TRANSACTION = "TRANSACTIONS";

void Database::openDatabase(std::string dbFile) {
    /* Open database */
    rc = sqlite3_open(dbFile.c_str(), &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
       throw "Unable to open database";
    } else {
        fprintf(stdout, "Opened database successfully\n");
        connected = true;
    }
}

bool Database::dbFileExists(std::string dbFile) {
    return fileExists(dbFile);
}

bool Database::isConnected() {
    return connected;
}

void Database::closeDataBase() {
    rc = sqlite3_close(db);
    if( rc ) {
        fprintf(stderr, "Can't close database: %s\n", sqlite3_errmsg(db));
        throw "Unable to close database";
    } else {
        fprintf(stdout, "Closed database successfully\n");
        connected = false;
    }
}

bool Database::insertTransaction(Transaction t) {

    sqlite3_stmt *stmt;
    const char *pzTest;
    const char *szSQL;
    std::string sql;

    // Insert data item into Transaction table
    std::string table = Database::TABLE_TRANSACTION;
    sql = "insert into " + table + " ("
                                   "ID, "
                                   "RESERVATION_DATE, "
                                   "RECEIVER, "
                                   "SENDER, "
                                   "BALANCE_BEFORE_TRANSACTION, "
                                   "MUTATION_VALUE, "
                                   "PROCESSING_DATE, "
                                   "DESCRIPTION, "
                                   "TRANSACTION_CODE, "
                                   "ANNOTATED"
                                   ") values (?,?,?,?,?,?,?,?,?,?)";

    szSQL = sql.c_str();
    rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);
    if( rc ) {
        fprintf(stderr, "Can't create statement: %s\n", sqlite3_errmsg(db));
        throw "Unable to create statement";
        return false;
    } else {
        // bind the value
        sqlite3_bind_int(stmt, 1, t.getIndex());
        sqlite3_bind_int(stmt, 2, t.getReservationDate());
        sqlite3_bind_text(stmt, 3, t.getReceiverAccountReference().c_str(), strlen(t.getReceiverAccountReference().c_str()), 0);
        sqlite3_bind_text(stmt, 4, t.getSenderAccountReference().c_str(), strlen(t.getSenderAccountReference().c_str()), 0);

        sqlite3_bind_double(stmt, 5, t.getBalanceBeforeTransaction());
        sqlite3_bind_double(stmt, 6, t.getMutationValue());
        sqlite3_bind_double(stmt, 7, t.getProcessDate());
        sqlite3_bind_text(stmt, 8, t.getDescription().c_str(), strlen(t.getDescription().c_str()), 0);
        sqlite3_bind_text(stmt, 9, t.getTransactionCode().c_str(), strlen(t.getTransactionCode().c_str()), 0);
        sqlite3_bind_int(stmt, 10, 0);

        // commit
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        return true;
    }
}

bool Database::updateTransaction(Transaction t) {
    return false;
}

bool Database::deleteTransaction(Transaction t) {
    return false;
}

int Database::numberOfTransaction() {
    return 0;
}

int Database::tableSize(std::string tableName) {
    return 0;
}

bool Database::emptyDatabase(std::string dbFileName) {
    return false;
}

bool Database::tableExists(std::string tableName) {

    return false;
}

bool Database::emptyTable(std::string tableName) {
    return false;
}

bool Database::dropTable(std::string tableName) {
    std::string sql = "DROP TABLE " + tableName;
    char* messaggeError;
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);

    if (rc) {
        std::cerr << "Error Drop Table" << std::endl;
        fprintf(stderr, "Can't Drop table: %s\n", sqlite3_errmsg(db));
        sqlite3_free(messaggeError);
        return false;
    }
    else
        std::cout << "Table dropped Successfully" << std::endl;
    return true;
}

bool Database::tableIsEmpty(std::string tableName) {
    sqlite3_stmt *stmt;
    std::string sql = "SELECT 1 FROM " + tableName + " LIMIT 1";
    const char *szSQL;
    const char *pzTest;
    szSQL = sql.c_str();

    rc = sqlite3_prepare_v2(db, szSQL, -1, &stmt, &pzTest);

    if (rc) {
        return false;
    }
    return true;
}

bool Database::fileExists(std::string pathToFile) {
    return boost::filesystem::exists(pathToFile);
}

bool Database::createTransactionTable() {
    std::string sql = "CREATE TABLE TRANSACTIONS("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "RESERVATION_DATE           INT    NOT NULL, "
                      "RECEIVER          TEXT     NOT NULL, "
                      "SENDER            TEXT     NOT NULL, "
                      "BALANCE_BEFORE_TRANSACTION        DOUBLE NOT NULL, "
                      "MUTATION_VALUE         DOUBLE NOT NULL,"
                      "PROCESSING_DATE  INT NOT NULL,"
                      "DESCRIPTION TEXT NOT NULL,"
                      "TRANSACTION_CODE TEXT NOT NULL, "
                      "ANNOTATED INT DEFAULT 0);";
    char* messaggeError;
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);

    if (rc) {
        std::cerr << "Error Create Table" << std::endl;
        fprintf(stderr, "Can't create table: %s\n", sqlite3_errmsg(db));
        sqlite3_free(messaggeError);
        return false;
    }
    else
        std::cout << "Table created Successfully" << std::endl;
    return true;
}

bool Database::rowExists(std::string tableName, int id) {

    sqlite3_stmt *stmt;
    std::string sql = "SELECT 1 FROM " + tableName + " WHERE ID= ?1 LIMIT 1";
    const char *szSQL;
    const char *pzTest;
    szSQL = sql.c_str();

    rc = sqlite3_prepare_v2(db, szSQL, -1, &stmt, &pzTest);

    if (rc == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);
    } else {
        return false;
    }
    return true;

//    int step = sqlite3_step(stmt);
//
//    if (step == SQLITE_ROW) {
//
//        printf("%d: ", sqlite3_column_int(stmt, 0));
//        printf("%d\n", sqlite3_column_int(stmt, 1));
//
//    }
//
//    sqlite3_finalize(stmt);
//
//    return false;
}
