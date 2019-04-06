//
// Created by bart on 6-4-19.
//

#include <iostream>
#include "api/Transaction.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello Money Insight" << std::endl;

    Transaction t(0, 1, "bart", "cox", 0, 0, 0, "Test transaction" ,"ACC");

    std::cout << t << std::endl;
    return 0;
}
