#include <iostream>
#include <vector>
#include "merklemain.h"
#include "OrderBookEntry.h"

// Implementacja funkcji klasy głównej (wycięcie z pliku main.cpp)

//Konstruktor klasy MerkleMain
MerkleMain::MerkleMain(){

}

/** your main function should call this */
void MerkleMain::init(){
    loadOrderBook();
    int input;
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOptions(input);
        if (input == 9){
            std::cout << std::endl;
            std::cout << "See you next time!" << std::endl << std::endl;
            break;
        }
    }
    
}
/** load up some dummy data for now */
void MerkleMain::loadOrderBook(){

    // OrderBookEntry order1(10000.0, 0.00002, "2020/03/17 17:01:30.099017", "BTC/USDT", OrderBookType::ask);

    // Przekazywanie konstruktora klasy do vectora
    orders.push_back(OrderBookEntry{
                    10000,
                    0.02,
                    "2020/03/17 17:01:30.099017",
                    "BTC/USDT",
                    OrderBookType::ask} 
                );

    orders.push_back(OrderBookEntry{
                    20000,
                    0.03,
                    "2020/03/17 17:21:30.099017",
                    "BTC/USDT",
                    OrderBookType::bid} 
                );
    // Iteracje po wektorach
    // 1.1. Iteracja kopiująca dane z obiektu klasy
    // for (OrderBookEntry order : orders){
    //     std::cout << "The price is: " << order.price << std::endl;
    // }
}
// funkcja wyswietlania opcji
void MerkleMain::printMenu(){
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl << std::endl;
    // 1 printing help
    std::cout << "1: Print help." << std::endl;
        // 2 printing exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
        // 3 make an offer
    std::cout << "3: Make an offer" << std::endl;
        // 4 make a bid
    std::cout << "4: Make a bid" << std::endl;
        // print wallet
    std::cout << "5: Print wallet" << std::endl;
        // 6 continue
    std::cout << "6: Continue" << std::endl;
        //9 exit
    std::cout <<"9: EXIT See you next time" << std::endl << std::endl;
}

void MerkleMain::printHelp(){std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers" << std::endl << std::endl;
}

void MerkleMain::printStats(){
    std::cout << "OrderBook contains: " << orders.size() << " entries" << std::endl << std::endl;
    
}

void MerkleMain::makeOffer(){
   std::cout << "Mark an offer" << std::endl << std::endl;
   
}

void MerkleMain::makeBid(){
    std::cout << "Make a bid - enter an amount" << std::endl << std::endl;
    
}

void MerkleMain::printWallet(){
    std::cout << "Your wallet is empty. " << std::endl << std::endl;
} 

void MerkleMain::goToNextTimeFrame(){
    std::cout << "Going to next time frame" << std::endl << std::endl;
    
}


// funkcja interakcji z użytkownikiem
int MerkleMain::getUserOption(){
    std::cout << "================================" << std::endl << std::endl;
    std::cout << "Select option 1 -6" << std::endl << std::endl;
    int userOption;
    std::cin >> userOption;
    std::cout << std::endl << "You chose: " << userOption << std::endl << std::endl;
    std::cout << "================================" << std::endl;
    return userOption;
}

/**  funkcja warunków */
void MerkleMain::processUserOptions(int userOption){

    if (userOption == 0){
        std::cout << "Invalid choose, please select 1-6" << std::endl << std::endl;
    }
    if (userOption == 1){
        printHelp();
    }
    if (userOption == 2){
        printStats();
    }
    if (userOption == 3){
        makeOffer();
    }
    if (userOption == 4){
        makeBid();
    }
    if (userOption == 5){
        printWallet();
    }
    if (userOption == 6){
        goToNextTimeFrame(); 
    }
    if (userOption == 7 || userOption == 8){
        std::cout << "Invalid choose, please select 1-6" << std::endl << std::endl;
    }
    if (userOption >= 10){
        std::cout << "Invalid choose, please select 1-6" << std::endl << std::endl;
    }
    
}