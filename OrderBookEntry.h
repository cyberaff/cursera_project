#pragma once
#include <string>

//Plik header '.h' jest definicją klasy

enum class OrderBookType {ask, bid, sale, unkonown};


// Definiowanie klasy: class nazwa_klasy {}; bez srednika na końcu klasa nie może zostać wywołana
// Definicja klasy ze zmiennymi publicznymi
/**Class to create the object of OrderBookEntries */
class OrderBookEntry{

    public:
    OrderBookEntry(double price, 
                   double amount, 
                   std::string timeStamp, 
                   std::string product, 
                   OrderBookType orderType);

    static OrderBookType stringToOBT(std::string);
    
    /**Function created to comper timestamps in Order Book */
    static bool comperByTimeStamp(OrderBookEntry& e1, OrderBookEntry& e2){
        return e1.timeStamp < e2.timeStamp;
    }
    static bool comperByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2){
        return e1.price < e2.price;
    }
    static bool comperByPriceDsc(OrderBookEntry& e1, OrderBookEntry& e2){
        return e1.price > e2.price;
    }

    double price;
    double amount;
    std::string timeStamp;
    std::string product;
    OrderBookType orderType;
    
};