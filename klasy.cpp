#include <iostream>
#include <string>

enum class OrderBookType {ask, bid};


// Definiowanie klasy: class nazwa_klasy {}; bez srednika na końcu klasa nie może zostać wywołana
// Definicja klasy ze zmiennymi publicznymi
class OrderBookEntry{
    public:
    OrderBookEntry(double price, double amount, std::string timeStamp, std::string product, OrderBookType orderType)
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

    OrderBookEntry order1(10000.0, 0.00002, "2020/03/17 17:01:30.099017", "BTC/USDT", OrderBookType::ask);

    std::cout << "The price is: " << order1.price << std::endl;
    std::cout << "The amount is: " << order1.amount << std::endl;
    std::cout << "The timeStamp is: " << order1.timeStamp << std::endl;
    std::cout << "The product is: " << order1.product << std::endl;
    std::cout << "The order type is: " << orderBookTypeToString(order1.orderType) << std::endl;

    return 0;
}