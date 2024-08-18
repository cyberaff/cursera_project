#include <iostream>
#include <string>
#include <map>


class Wallet
{
    public:
        Wallet();
        /** insert currency to the wallet */
        void insertCurrency(std::string type, double amount);

        /** chack if the wallet contains this much currency or more */
        bool containsCurrency(std::string type, double amount);

        /** generate a string representation of the wallet */
        std::string toString();

    private:

        /** function mapping a string to double needed for interaction */
        std::map<std::string, double> currencies;


};