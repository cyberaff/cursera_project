#pragma once
#include "OrderBookEntry.h"
#include <vector>
#include <string>

class CSVReader{

    public:
        CSVReader();
        
        // Static functions in class can be called without creating an instance of the class
        static std::vector<OrderBookEntry> readCSV(std::string csvFile);
        // Tokenise funtion need to be a public, we want to call it in other place
        static std::vector<std::string> tokenise(std::string csvFile, char separator);

        // This is another version of stringToBBE for purpose of makeAsk function
        static OrderBookEntry stringToOBE(std::string price,
                                          std::string amount,
                                          std::string timestamp,
                                          std::string product,
                                          OrderBookType OrderBookType);

    private:
        
        static OrderBookEntry stringToOBE(std::vector<std::string> strings);
};
