#pragma once
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>

class OrderBook
{
    public:
    /** construct, reading a csv file*/
        OrderBook(std::string filename);
    /** return vector of all know products in the dataset */
        std::vector<std::string> getKnownProducts();
    /**  return vector of Orders according to the sent filters */
        std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                              std::string product,
                                              std::string timestamp);
        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        static double getLowPrice(std::vector<OrderBookEntry>& orders);



    private:
    /** place to store csv file data */
        std::vector<OrderBookEntry> orders;

};