#pragma once
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "wallet.h"


//Utworzenie klasy głównej

class MerkleMain
{
    public:
        MerkleMain();
        /**Call this to start the sim */
        void init();
    
    private:
        // void loadOrderBook();
        void printMenu();
        void printHelp();
        void printStats();
        void makeAsk();
        void makeBid();
        void printWallet();
        void goToNextTimeFrame();
        // user interaction
        int getUserOption();
        /**  funkcja warunków */
        void processUserOptions(int userOption);

        std::string currentTime;
        OrderBook orderBook{"test_file.csv"};

        std::vector<OrderBookEntry> orders;
        
        Wallet wallet;
};


