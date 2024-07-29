#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum class OrderBookType {ask, bid};

// Definiowanie klasy: class nazwa_klasy {}; bez srednika na końcu klasa nie moze zostać wywołana


class OrderBookEntry{
    public:
    OrderBookEntry(double price, double amount, std::string timeStamp, std::string product, OrderBookType orderType)
    // Inicjalizacja danych w klasie
        :price(price), amount(amount), timeStamp(timeStamp), product(product), orderType(orderType)
    {
    }
    double price;
    double amount;
    std::string timeStamp;
    std::string product;
    OrderBookType orderType;
    
};

// funkcja wyswietlania opcji
void printMenu(){
    // 1 printing help
        cout << "1: Print help." << endl;
        // 2 printing exchange stats
        cout << "2: Print exchange stats" << endl;
        // 3 make an offer
        cout << "3: Make an offer" << endl;
        // 4 make a bid
        cout << "4: Make a bid" << endl;
        // print wallet
        cout << "5: Print wallet" << endl;
        // 6 continue
        cout << "6: Continue" << endl;
        // 9 exit
        cout <<"9: EXIT See you next time" << endl << endl;
}

void printHelp(){
    cout << "Help - yor=ur aim is to make money. Analyse the market and make bids and offers" << endl
                << endl;
}

void printStats(){
    cout << "Market looks good" << endl << endl;
}

void makeOffer(){
    cout << "Mark an offer" << endl << endl;
}

void makeBid(){
    cout << "Make a bid - enter an amount" << endl << endl;
}

void printWallet(){
    cout << "Your wallet is empty. " << endl << endl;
}

void goToNextTimeFrame(){
    cout << "Going to next time frame" << endl << endl;
}


// funkcja interakcji z użytkownikiem
int getUserOption(){
    cout << "================================" << endl << endl;
    cout << "Select option 1 -6" << endl << endl;
    int userOption;
    cin >> userOption;
    cout << endl << "You chose: " << userOption << endl << endl;
    return userOption;
}

/**  funkcja warunków */
void processUserOptions(int userOption){
    if (userOption == 0){
        cout << "Invalid choose, please select 1-6" << endl << endl;
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
        cout << "Invalid choose, please select 1-6" << endl << endl;
    }
};


int main(){
    
    // double price = 5352.00076616;
    // double amount = 0.4973764;

    // // Deklaracja zmiennych typ string: string nazwa{"rodzajStringu"}<-konstruktor
    // // String jest klasą więc potrzebujemy wywołać konstruktor
    // std::string timestamp{"2020/03/17 17:01:30.099017"};
    // string product{"BTC/USDT"};
    // // Tworzenie nowego typu zmiennych
    // 
    // // Deklarujemy zmienna typu OrderBookType
    // OrderBookType orderType = OrderBookType::bid;
    
    // Tworzenie vectorów do przechowywania dużej ilości danych dla jednej zmiennej
    // std::vector<double> prices;
    // std::vector<double> amounts;
    // std::vector<std::string> timeStamps;
    // std::vector<std::string> products;
    // std::vector<OrderBookType> orderTypes;

    // // Przekazywanie danych do vectorów
    // // Vectory przechowuja dane tylko jednego typu
    // prices.push_back(5352.00076616);
    // prices.push_back(10);
    // amounts.push_back(0.4973764);
    // timeStamps.push_back("2020/03/17 17:01:30.099017");
    // products.push_back("BTC/USDT");
    // orderTypes.push_back(OrderBookType::ask);

    // // Wyjęcie danych z vectorów (po indexach)
    // cout << "Price: " << prices[0] << endl;
    // cout << "Price: " << prices[1] << endl;


    // // tworzymy pętle dla interakcji z uzytkownikiem
    // while (true){
    // // opcje:
    //     cout << endl;
    //     printMenu();
    //     int userOption = getUserOption();
    //     processUserOptions(userOption);

    // // wychodzimy z pętli po klawiszu 9
    //     if (userOption == 9){
    //         cout << " See you next time" << endl;
    //         break;
    //     }
        
    // }
    OrderBookEntry order1{10000, 
                        0.02,   
                        "2020/03/17 17:01:30.099017", 
                        "BTC/USDT", 
                        OrderBookType::bid};

    std::cout << "The price is: " << order1.price << std::endl;

    return 0;
}
