#include <iostream>
#include "Set.h"

int main() {


    Set proverka(100);    
    for (size_t i = 0; i < 100; i++) {
        proverka.InserElem(i);
    }
    
    std::cout << "res = ";    
    std::vector<uint64_t> prost = proverka.GetPrimary();    
    for (int i = 0; i < 25; i++) {
        std::cout << prost[i] << " ";
    }    
    std::cout << std::endl;
    /*uint16_t a = 1;
    //a = a << 10;
    std::cout << a << std::endl;
    uint8_t b = 0;
    b = static_cast<uint8_t>(a);
    std::cout << static_cast<uint32_t>(b) << std::endl;
    return 0;*/
}