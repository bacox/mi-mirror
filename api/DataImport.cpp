//
// Created by bart on 8-4-19.
//

#include <iostream>
#include <fstream>
#include "DataImport.h"
#include "models/Transaction.h"
#include <boost/algorithm/string.hpp>
#include <vector>

void DataImport::fromCSVStringBuffer(std::string stream) {
    std::vector<std::string> lines;
    boost::split(lines, stream, boost::is_any_of("\r\n"));

    std::cout << "Contents of the stringstream: ";
//    std::cout << lines.size() << std::endl;
    for( std::string s : lines)
    {
        std::vector<std::string> parts;
        boost::split(parts, s, boost::is_any_of(","));
        if(parts.size() == 1)
            continue;
//        std::cout << "> " << s << std::endl;

        // Remove all space from each cell
        std::for_each(parts.begin(), parts.end(), [](std::string &n){ boost::trim(n); });
//
//
//        // Get index
        long index = std::stol(parts[15]);
        int reservationDate = 0;
        std::string receiver = parts[1];
        std::string sender = parts[2];
        std::string senderName = parts[3];
        double balanceBeforeTransaction = std::stod(parts[8]);
        double mutationValue = std::stod(parts[10]);
        int processingDate = 0;
        std::string description = parts[17];
        std::string transactionCode = parts[14];
        Models::Transaction t(
                index,
                reservationDate,
                receiver,
                sender,
                balanceBeforeTransaction,
                mutationValue,processingDate,
                description,
                transactionCode);


        std::cout << t << std::endl;
    }
}

std::string DataImport::fromCSVFile(std::string filename) {
    std::ifstream f(filename);
    std::stringstream buf;
    buf << f.rdbuf();
    std::string fileContents = buf.str();
    return fileContents;
}
