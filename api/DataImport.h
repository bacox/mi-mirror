//
// Created by bart on 8-4-19.
//

#ifndef MONEY_INSIGHT_DATAIMPORT_H
#define MONEY_INSIGHT_DATAIMPORT_H


#include <sstream>

class DataImport {
public:
    std::string fromCSVFile(std::string filename);
    void fromCSVStringBuffer(std::string);
};


#endif //MONEY_INSIGHT_DATAIMPORT_H
