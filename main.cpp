//
// Created by bart on 6-4-19.
//

#include <iostream>
#include "api/Transaction.h"
#include "api/TransactionBook.h"
#include "api/Database.h"
#include "api/DataImport.h"
#include "api/ApiHandler.h"

#include <mongoose/Server.h>
#include <mongoose/WebController.h>
#include <sqlite3.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    std::cout << "Hello Money Insight" << std::endl;

//    Transaction t(0, 1, "bart", "COX2", 0, 0, 0, "Test transaction" ,"ACC");
//    Transaction t2(1, 1, "bart", "COX_XOC", 0, 0, 0, "Test transaction" ,"ACC");
//
//    TransactionBook tb;
//
//    tb.addTransaction(t);
//    tb.addTransaction(t2);
//
//    Database db;
//    std::string dbFile = "./db.sqlite";
//    db.openDatabase(dbFile);
//    db.createTransactionTable();
//    db.insertTransaction(t);
//    db.insertTransaction(t2);
//    db.rowExists(Database::TABLE_TRANSACTION, 1);
//    db.tableExists("MyNewTable");
////    db.dropTable("TRANSACTIONS");
//
//    std::cout << tb << std::endl;

    std::string str = "1,2,3,4"
                      "5,6,7,8";

    DataImport di;
    std::string contents = di.fromCSVFile("../testdata/asn.csv");
    di.fromCSVStringBuffer(contents);
    std::cout << tb << std::endl;


    std::cout << "Starting webserver on port 8080" << std::endl;
    ApiHandler myController;
    Mongoose::Server server(8080);
    server.registerController(&myController);
    server.setOption("enable_directory_listing", "true");

    server.start();

    while (1) {
        usleep(10);
    }
    return 0;
}
