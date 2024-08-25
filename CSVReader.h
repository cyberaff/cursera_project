#pragma once
#include "OrderBookEntry.h"
#include <vector>
#include <string>

class CSVReader{

    public:
        CSVReader();
        
        // Static functions in class can be called without creating an instance of the class
        static std::vector<OrderBookEntry> readCSV(std::string csvFile);

    private:
        static std::vector<std::string> tokenise(std::string csvFile, char separator);
        static OrderBookEntry stringToOBE(std::vector<std::string> strings);
};
