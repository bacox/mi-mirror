//
// Created by bart on 12-4-19.
//

#ifndef MONEY_INSIGHT_REQUESTHANDLER_H
#define MONEY_INSIGHT_REQUESTHANDLER_H


#include <mongoose/WebController.h>
using namespace Mongoose;
class ApiHandler : public Mongoose::WebController{
public:
    void hello(Mongoose::Request &request, Mongoose::StreamResponse &response);

    void AddTransaction(Mongoose::Request &request, Mongoose::StreamResponse &response);

    void GetTransactions(Mongoose::Request &request, Mongoose::StreamResponse &response);

    void GetTransactionsById(Mongoose::Request &request, Mongoose::StreamResponse &response);
    //Setup routes

    void setup()
    {
            addRoute("GET", "/hello", ApiHandler , hello);
            addRoute("GET", "/api/transaction/add", ApiHandler , AddTransaction);
            addRoute("GET", "/api/transaction/getMany", ApiHandler , GetTransactions);
            addRoute("GET", "/api/transaction/get", ApiHandler , GetTransactionsById);
    }
};


#endif //MONEY_INSIGHT_REQUESTHANDLER_H
