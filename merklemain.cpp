#include <iostream>
#include "merklemain.h"

// Implementacja funkcji klasy głównej (wycięcie z pliku main.cpp)

//Konstruktor klasy MerkleMain
MerkleMain::MerkleMain(){

}

//Implementacja funkcji init
void MerkleMain::init(){
    int input;
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOptions(input);
    }
    
}

// funkcja wyswietlania opcji
void MerkleMain::printMenu(){
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
        // 9 exit
    std::cout <<"9: EXIT See you next time" << std::endl << std::endl;
}

void MerkleMain::printHelp(){std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers" << std::endl << std::endl;
}

void MerkleMain::printStats(){
    std::cout << "Market looks good" << std::endl << std::endl;
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
    
    if (userOption == 2)
    {
        printStats();
    }
    
    if (userOption == 3)
    {
        makeOffer();
    }
    
    if (userOption == 4)
    {
        makeBid();
    }
    
    if (userOption == 5)
    {
        printWallet();
    }
    
    if (userOption == 6)
    {
       goToNextTimeFrame(); 
    }

    if (6 > userOption < 9 and userOption >= 10)
    {
        std::cout << "Invalid choose, please select 1-6" << std::endl << std::endl;
    }

    if (userOption == 9){
        return;
    }
};