#pragma once
#include <string>

//Plik header '.h' jest definicją klasy

enum class OrderBookType {ask, bid, unkonown};


// Definiowanie klasy: class nazwa_klasy {}; bez srednika na końcu klasa nie może zostać wywołana
// Definicja klasy ze zmiennymi publicznymi
class OrderBookEntry{
    public:
    OrderBookEntry(double price, 
                   double amount, 
                   std::string timeStamp, 
                   std::string product, 
                   OrderBookType orderType);

    static OrderBookType stringToOBT(std::string);
    
    double price;
    double amount;
    std::string timeStamp;
    std::string product;
    OrderBookType orderType;
    
};