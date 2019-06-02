//
// Created by bart on 12-4-19.
//

#include "ApiHandler.h"

void ApiHandler::hello(Mongoose::Request &request, Mongoose::StreamResponse &response) {
    response << "Hello " << htmlEntities(request.get("name", "... what's your name ?")) << endl;
}

void ApiHandler::AddTransaction(Mongoose::Request &request, Mongoose::StreamResponse &response) {
    std::cout << "Api request" << std::endl;
    response << "Unimplemented";
}

void ApiHandler::GetTransactions(Mongoose::Request &request, Mongoose::StreamResponse &response) {
    std::cout << "Api request" << std::endl;
    response << "Unimplemented";
}

void ApiHandler::GetTransactionsById(Mongoose::Request &request, Mongoose::StreamResponse &response) {
    std::cout << "Api request" << std::endl;
    response << "Unimplemented";
}
