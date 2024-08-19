#pragma once
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"


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
        void makeOffer();
        void makeBid();
        void printWallet();
        void goToNextTimeFrame();
        // funkcja interakcji z użytkownikiem
        int getUserOption();
        /**  funkcja warunków */
        void processUserOptions(int userOption);

        OrderBook orderBook{"exaple_data.csv"};

        std::vector<OrderBookEntry> orders;
        
};


