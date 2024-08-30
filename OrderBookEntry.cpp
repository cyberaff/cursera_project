#include "OrderBookEntry.h"

//Plik '.cpp' jest implementacją definicji klasy z pliku '.h' więc musi być on zaimportowany (dodany).

OrderBookEntry::OrderBookEntry(double price, 
                               double amount, 
                               std::string timeStamp, 
                               std::string product, 
                               OrderBookType orderType,
                               std::string _username)
:price(price), 
 amount(amount), 
 timeStamp(timeStamp), 
 product(product), 
 orderType(orderType),
 username(username)
{

}
OrderBookType OrderBookEntry::stringToOBT(std::string s)
{
    if (s == "ask"){
        return OrderBookType::ask;
    } 
    if (s == "bid"){
        return OrderBookType::bid;
    }
    return OrderBookType::unkonown;
}