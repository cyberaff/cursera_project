#include <iostream>
#include <vector>

int main(){
    // vector fo strings called "strings"
    std::vector<std::string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    // iteratinf through the items in vectors "strings"
    // const prevent string by editing the original items
    //"&" prevent to making copy of the items - memory efficient
    for (const std::string& s : strings){
        std::cout << s << std::endl;
    }
}