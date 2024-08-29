#include <iostream>
#include <vector>
#include "merklemain.h"
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include "OrderBook.h"
#include <limits>

// Implementacja funkcji klasy głównej (wycięcie z pliku main.cpp)

//Konstruktor klasy MerkleMain
MerkleMain::MerkleMain(){

}

/** your main function should call this */
void MerkleMain::init(){
    // loadOrderBook();
    int input;
    currentTime = orderBook.getEarliestTime();
    
    wallet.insertCurrency("BTC", 10.0);
    
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

    std::cout << "Current time is: " << currentTime << std::endl << std::endl;
}

void MerkleMain::printHelp(){std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers" << std::endl << std::endl;
}

void MerkleMain::printStats(){

    for (std::string const& p : orderBook.getKnownProducts())
    {
        std::cout<< "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
                                                        p, 
                                                        currentTime);
        std::cout << "ASKs seen: " << entries.size() << std::endl;
        std::cout << "Max asks: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min asks: " << OrderBook::getLowPrice(entries) << std::endl;
    }
    // std::cout << "OrderBook contains: " << orders.size() << " entries" << std::endl << std::endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;
    // for (OrderBookEntry& e : orders){
    //     if (e.orderType == OrderBookType::ask){
    //         asks ++;
    //     }
    //     if (e.orderType == OrderBookType::bid){
    //         bids ++;
    //     }
    // }
    //     std::cout << "   asks: " << asks 
    //     << std::endl << "   and bids: " << bids << std::endl << std::endl;

}

void MerkleMain::makeAsk(){
    std::cout << "Make an ask - enter the amount: product, price, amount "
    "eg. ETH/BTC,200,0.5 " << std::endl << std::endl;
    std::cout << "Ask: ";
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3){
        std::cout << "You entered wrong ask!" << std::endl;
    }
    else {
        try{
            OrderBookEntry obe = CSVReader::stringToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::ask);
            orderBook.insertOrder(obe);
        }catch (const std::exception& e){
            std::cout << "MerkleMain::makeAsk - bad input! It should be like this: ETH/BTC,200,0.5" << std::endl;
        }
    }
    
    std::cout << std::endl << "You entered: " << input << std::endl;
}

void MerkleMain::makeBid(){
    std::cout << "Make a bid - enter an amount" << std::endl << std::endl;
    
}

void MerkleMain::printWallet(){
    std::cout << "Your wallet is empty. " << std::endl << std::endl;
    std::cout << wallet.toString() << std::endl;
} 

void MerkleMain::goToNextTimeFrame(){
    std::cout << "Going to next time frame" << std::endl << std::endl;
    std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids("ETH/BTC", currentTime);
    std::cout << "Sales: " << sales.size() << std::endl;
    for (OrderBookEntry& sale : sales){
        std::cout << "Sale price: " << sale.price << " Sale amount: " << sale.amount << std::endl;
    }
    currentTime = orderBook.getNextTime(currentTime);
    
}


// funkcja interakcji z użytkownikiem
int MerkleMain::getUserOption(){
    int userOption = 0;
    std::string line;
    std::cout << "================================" << std::endl << std::endl;
    std::cout << "Select option 1 -6" << std::endl << std::endl;
    std::getline(std::cin, line);
    
    try{
        userOption = std::stoi(line);
    }catch(const std::exception e){
        std::cout << "MerkleMain::getUserOption - Enter the wright number" << std::endl;
    }

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
        makeAsk();
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