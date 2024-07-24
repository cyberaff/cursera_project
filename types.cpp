#include <iostream>

int main(){
    char c = 0;
    std::cout << "char: " << sizeof(c) << std::endl;

    char16_t c_16 = 0;
    std::cout << "char_16: " << sizeof(c_16) << std::endl;

    char32_t c_32 = 0;
    std::cout << "char_32: " << sizeof(c_32) << std::endl;

    int i = 0;
    std::cout << "int: " << sizeof(i) << std::endl;

    unsigned int i_u = 0;
    std::cout << "int: " << sizeof(i_u) << std::endl;

    float f = 0.0f;
    std::cout << "float: " << sizeof(f) << std::endl;

    double d = 0.0;
    std::cout << "double: " << sizeof(d) << std::endl;

    long double l = 0.0;
    std::cout << "long: " << sizeof(l) << std::endl;

    return 0;
}