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
    // std::cout << std::endl;
    // std::cout << "The price is: " << orders[1].price << std::endl;
    // std::cout << "The amount is: " << orders[1].amount << std::endl;
    // std::cout << "The timeStamp is: " << orders[1].timeStamp << std::endl;
    // std::cout << "The product is: " << orders[1].product << std::endl;
    // std::cout << "The order type is: " << orderBookTypeToString(orders[1].orderType) << std::endl;
    // std::cout << std::endl;
    
    // Iteracje po wektorach
    // 1.1. Iteracja kopiująca dane z obiektu klasy
    // for (OrderBookEntry order : orders){
    //     std::cout << "The price is: " << order.price << std::endl;
    // }

    
    // 1.2.Iteracja nie kopiująca danych a pracująca na referencji do obiektu klasy odbywa się przez dodanie & po wywołaniu klasy
    //Bardziej efektywna
    // for(OrderBookEntry& order: orders){
    //     std::cout << "The price is: " << order.price << std::endl;
    // }

    // 2. Iteracja w pętli array syntax
    /*
    Inicjujemy zmienną usigned int i - dla indeksów wektora, dodajemy warunek, że i musi byc mniejsze od wielkości wektora,
    oraz inkrementujemy i (++i nie kopjuje danych inkrementuje bezpośrednio, natomiast i++ najpierw przechodzi przez pętle,
    kopijuje dane i dopiero inkrementuje i dodaje dane)
    */
    // for (unsigned int i=0; i < orders.size(); ++i)
    // {
    //     std::cout << "The price is: " << orders[i].price << std::endl;
    // }

    // 3. Iteracja w pętli w stylu obiektowym - zamiast odniesienia do indeksu w [] 
    // odnosimy się przez funkcję at() jako argument podajemy nasze i
    for(unsigned int i; i < orders.size(); ++i)
    {
        std::cout << "The price is: " << orders.at(i).price << std::endl;
    }
    return 0;
}