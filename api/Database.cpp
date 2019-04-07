//
// Created by bart on 7-4-19.
//

#include <boost/filesystem/operations.hpp>
#include "Database.h"

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
    return false;
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
    return false;
}

bool Database::tableIsEmpty(std::string tableName) {
    return false;
}

bool Database::fileExists(std::string pathToFile) {
    return boost::filesystem::exists(pathToFile);
}
