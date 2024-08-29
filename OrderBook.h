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

        /** Return staistic of the highest price */
        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        /** Return staistic of the lowest price */
        static double getLowPrice(std::vector<OrderBookEntry>& orders);

        /**return the erliest time in the order book */
        std::string getEarliestTime();
        /** return next time after 
         * the sent time in the order book 
         * if there is no next timestamp, wraps around to the strt.*/
        std::string getNextTime(std::string timestamp);

        /** Function to insert an created order*/
        void insertOrder(OrderBookEntry& order);

        std::vector<OrderBookEntry> matchAsksToBids(std::string product,
                                                    std::string timestamp);

    private:
    /** place to store csv file data */
        std::vector<OrderBookEntry> orders;

};
