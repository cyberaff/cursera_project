#include "OrderBookEntry.h"

//Plik '.cpp' jest implementacją definicji klasy z pliku '.h' więc musi być on zaimportowany (dodany).

OrderBookEntry::OrderBookEntry(double _price, 
                               double _amount, 
                               std::string _timeStamp, 
                               std::string _product, 
                               OrderBookType _orderType,
                               std::string _username)
:price(_price), 
 amount(_amount), 
 timeStamp(_timeStamp), 
 product(_product), 
 orderType(_orderType),
 username(_username)
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