#pragma once
#include <iostream>
#include <string>
#include <map>
#include "OrderBook.h"


class Wallet
{
    public:
        Wallet();
        /** insert currency to the wallet */
        void insertCurrency(std::string type, double amount);

        /** remove currency from the wallet */
        bool removeCurrency(std::string type, double amount);

        /** chack if the wallet contains this much currency or more */
        bool containsCurrency(std::string type, double amount);

        /**Check if the wallet can cope with this ask or bid */
        bool canFulfillOrder(const OrderBookEntry& order);

        /**Update the content of the wallet
         * assumes the order was made by the owner of the wallet
         */
        void processSale(OrderBookEntry& sale);

        /** generate a string representation of the wallet */
        std::string toString();

    private:

        /** function mapping a string to double needed for interaction */
        std::map<std::string, double> currencies;


};