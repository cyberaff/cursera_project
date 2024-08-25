#include "OrderBook.h"
#include "CSVReader.h"
#include <map>

/** construct, reading a csv file*/
    OrderBook::OrderBook(std::string filename)
    {
        orders = CSVReader::readCSV(filename);
    }
/** return vector of all know products in the dataset */
    std::vector<std::string> OrderBook::getKnownProducts()
    {
        std::vector<std::string> products;
        
        std::map<std::string, bool> prodMap;

        for (OrderBookEntry& e : orders)
        {
            prodMap[e.product] = true;
        }

        // now flatten the map to a vector of strings
        for (auto const& e : prodMap)
        {
            products.push_back(e.first);
        }
        
        return products;
    }
/**  return vector of Orders according to the sent filters */
    std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                              std::string product,
                                              std::string timestamp)
    {
        std::vector<OrderBookEntry> oreders_sub;
        for (OrderBookEntry& e : orders){
            if (e.orderType == type &&
                e.product == product &&
                e.timeStamp == timestamp){
                    oreders_sub.push_back(e);
                }
        }
        return oreders_sub;
    }