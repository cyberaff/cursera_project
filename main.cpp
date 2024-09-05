#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "merklemain.h"
#include "CSVReader.h"
#include "wallet.h"



int main(){
    Wallet wallet{};
    MerkleMain app{};
    app.init();
    // Wallet wallet;
   
    // wallet.insertCurrency("BTC", 10);
    // wallet.insertCurrency("USDT", 10000);
    // std::cout << "Balance: " << std::endl << wallet.toString() << std::endl;
    // wallet.removeCurrency("USDT", 5000);
    // std::cout << "Balance: "<< std::endl << wallet.toString() << std::endl;
    
    // wallet.removeCurrency("ETH", 5000);
    
    // wallet.insertCurrency("BTC", -50);
    // wallet.insertCurrency("USDT", -50);
    
    // wallet.removeCurrency("BTC", -50);
 }
    
    
    
    
  

