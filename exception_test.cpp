#include <string>
#include <iostream>

using namespace std;

int main(){

    double d = 0;
    string s = "and";
    try
    {
        d = stod(s);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "Bad double value" << endl;
    }
    
    cout << "d: " << d << endl;
}

