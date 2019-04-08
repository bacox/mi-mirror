//
// Created by bart on 6-4-19.
//

#include <iostream>
#include "api/Transaction.h"
#include "api/TransactionBook.h"
#include "api/Database.h"
#include <mongoose/Server.h>
#include <mongoose/WebController.h>
#include <sqlite3.h>
#include <unistd.h>


using namespace Mongoose;

class MyController : public WebController
{
public:
    void hello(Request &request, StreamResponse &response)
    {
        response << "Hello " << htmlEntities(request.get("name", "... what's your name ?")) << endl;
    }

    void setup()
    {
        addRoute("GET", "/hello", MyController, hello);
    }
};

int main(int argc, char *argv[])
{
    std::cout << "Hello Money Insight" << std::endl;

    Transaction t(0, 1, "bart", "COX2", 0, 0, 0, "Test transaction" ,"ACC");
    Transaction t2(1, 1, "bart", "COX_XOC", 0, 0, 0, "Test transaction" ,"ACC");

    TransactionBook tb;

    tb.addTransaction(t);
    tb.addTransaction(t2);

    Database db;
    std::string dbFile = "./db.sqlite";
    db.openDatabase(dbFile);
    db.createTransactionTable();
    db.insertTransaction(t);
    db.insertTransaction(t2);
    db.rowExists(Database::TABLE_TRANSACTION, 1);
    db.tableExists("MyNewTable");
//    db.dropTable("TRANSACTIONS");

    std::cout << tb << std::endl;


    std::cout << "Starting webserver on port 8080" << std::endl;
    MyController myController;
    Server server(8080);
    server.registerController(&myController);

    server.start();

    while (1) {
        usleep(10);
    }
    return 0;
}
