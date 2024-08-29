#include "wallet.h"
#include <iostream>
#include "CSVReader.h"

Wallet::Wallet()
{

}

void Wallet::insertCurrency(std::string type, double amount){
    double balance;
    try{
        if (amount < 0){
            throw std::invalid_argument("Can't add negative amount.");
        }
        if (currencies.count(type) == 0){   //not there yet
            balance = 0;
        }
        else{                               // is there
            balance = currencies[type];
        }
        balance += amount;
        currencies[type] = balance;
        std::cout << "You add " << type << " : " << amount << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

bool Wallet::removeCurrency(std::string type, double amount){
    double balance;
    try{
        if (amount < 0){
            throw std::invalid_argument("Can't remove negative amount.");
        }
        if (currencies.count(type) == 0){   //not there yet
            std::cout << "You try to remove " << type << " but the wallet not contains currency for " << type << std::endl;
            return false;
        }
        else{                               // is there - do we have enough
            if (containsCurrency(type,amount)){
                std::cout << "Removing " << type << " : " << amount << std::endl;
                currencies[type] -= amount;
                return true;
            }
            else                            // not enough
                return false;
        }
    }
    catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return false;
}

bool Wallet::containsCurrency(std::string type, double amount){
    if (currencies.count(type) == 0)
        return false;
    else
        return currencies[type] >= amount;
}

std::string Wallet::toString(){
    std::string s;
    for (std::pair<std::string,double> pair : currencies){
        std::string currency = pair.first;
        double amount = pair.second;
        s += currency + " : " + std::to_string(amount) + "\n";
    }
    
    return s;
}

bool Wallet::canFulfillOrder(const OrderBookEntry& order){
    std::vector<std::string> currs = CSVReader::tokenise(order.product, '/');
    //ask
    if (order.orderType == OrderBookType::ask){
        double amount = order.amount;
        std::string currency = currs[0];
        std::cout << "Wallet::canFulfillOrder " << currency << " : " << amount << std::endl;
        return containsCurrency(currency, amount);
    }

    //bid 
    if (order.orderType == OrderBookType::bid){
        double amount = order.amount * order.price;
        std::string currency = currs[1];
        std::cout << "Wallet::canFulfillOrder " << currency << " : " << amount << std::endl;
        return containsCurrency(currency, amount);
    }
    return false;
}