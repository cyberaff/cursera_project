#include "CSVReader.h"
#include <iostream>
#include "OrderBookEntry.h"
#include <fstream>

CSVReader::CSVReader(){

};

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename)
{
    
    std::vector<OrderBookEntry> entrries;
    std::ifstream csvFile{csvFilename}; //open the file in read option by defult
    std::string line;
    if (csvFile.is_open())
    {
        while(std::getline(csvFile, line))
        {
            try{
                OrderBookEntry obe = stringToOBE(tokenise(line, ','));
                entrries.push_back(obe);
            }catch(const std::exception e){
                std::cout << "CSVReader::readCSV read bad line" << std::endl;
            }
        }
    }
    std::cout << "CSVReader::readCSV read " << entrries.size() << "entries" << std::endl;
    return entrries;

}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;
    start = csvLine.find_first_not_of(separator, 0);
    do{
        end = csvLine.find_first_of(separator, start);
        if(start == csvLine.length() || start == end) break;
        if(end >= 0) token = csvLine.substr(start, end - start);
        else 
            token = csvLine.substr(start, csvLine.length() - start);
            tokens.push_back(token);
            start = end + 1;

    }while(end != std::string::npos); //because find_first_not_of returns std::string::npos if it does not find the search term.


    return tokens;
}

OrderBookEntry CSVReader::stringToOBE(std::vector<std::string> tokens)
{
    double price, amount;

    if(tokens.size() != 5){  
                std::cout << "Bad line " << std::endl;
                throw std::exception();   
    }

    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);        
    }
    catch(const std::exception& e)
    {
        std::cout << "Bad float! " << tokens[3] << std::endl;
        std::cout << "Bad float! " << tokens[4] << std::endl;
        throw;
    }
    OrderBookEntry obe{price,
                        amount,
                        tokens[0],
                        tokens[1],
                        OrderBookEntry::stringToOBT(tokens[2])};
    return obe;
};
