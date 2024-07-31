#include "OrderBookEntry.h"

//Plik '.cpp' jest implementacją definicji klasy z pliku '.h' więc musi być on zaimportowany (dodany).

OrderBookEntry::OrderBookEntry(double price, 
                               double amount, 
                               std::string timeStamp, 
                               std::string product, 
                               OrderBookType orderType)
:price(price), 
 amount(amount), 
 timeStamp(timeStamp), 
 product(product), 
 orderType(orderType)
{

}