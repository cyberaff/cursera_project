#include <iostream>
#include <string>
#include <vector>

enum class OrderBookType {ask, bid};


// Definiowanie klasy: class nazwa_klasy {}; bez srednika na końcu klasa nie może zostać wywołana
// Definicja klasy ze zmiennymi publicznymi
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

// Funkcja do odczytu (stringa) typu danych przekazywanych do enumeratora OrderBookType
std::string orderBookTypeToString(OrderBookType type){
    switch (type)
    {
        case OrderBookType::ask: return "ask";
        case OrderBookType::bid: return "bid";
        default: return "unknown";
    }
}

int main(){

    std::vector<OrderBookEntry> orders;

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
    std::cout << std::endl;
    std::cout << "The price is: " << orders[1].price << std::endl;
    std::cout << "The amount is: " << orders[1].amount << std::endl;
    std::cout << "The timeStamp is: " << orders[1].timeStamp << std::endl;
    std::cout << "The product is: " << orders[1].product << std::endl;
    std::cout << "The order type is: " << orderBookTypeToString(orders[1].orderType) << std::endl;
    std::cout << std::endl;
    return 0;
}