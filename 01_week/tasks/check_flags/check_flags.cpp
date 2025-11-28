#include <cstdint>
#include <stdexcept>
#include <iostream>


enum class CheckFlags : uint8_t {
    NONE = 0,         //0
    TIME = (1 << 0),  //1
    DATE = (1 << 1),  //2
    USER = (1 << 2),  //4
    CERT = (1 << 3),  //8
    KEYS = (1 << 4),  //16
    DEST = (1 << 5),  //32
    ALL = TIME | DATE | USER | CERT | KEYS | DEST
};

void PrintCheckFlags(CheckFlags flags) {
    if (flags <= CheckFlags::ALL && flags >= CheckFlags::NONE){
        std::cout << "[";
        bool prev_print = 0;
        if (static_cast<uint8_t>(flags) & static_cast<uint8_t>(CheckFlags::TIME)){
            if (prev_print == 1){
                std::cout << ",";
            }
            std::cout << "TIME";
            prev_print = 1;
        }
        if (static_cast<uint8_t>(flags) & static_cast<uint8_t>(CheckFlags::DATE)){
            if (prev_print == 1){
                std::cout << ",";
            }
            std::cout << "DATE";
            prev_print = 1;
        }
        if (static_cast<uint8_t>(flags) & static_cast<uint8_t>(CheckFlags::USER)){
            if (prev_print == 1){
                std::cout << ",";
            }
            std::cout << "USER";
            prev_print = 1;
        }
        if (static_cast<uint8_t>(flags) & static_cast<uint8_t>(CheckFlags::CERT)){
            if (prev_print == 1){
                std::cout << ",";
            }
            std::cout << "CERT";
            prev_print = 1;
        }
        if (static_cast<uint8_t>(flags) & static_cast<uint8_t>(CheckFlags::KEYS)){
            if (prev_print == 1){
                std::cout << ",";
            }
            std::cout << "KEYS";
            prev_print = 1;
        }
        if (static_cast<uint8_t>(flags) & static_cast<uint8_t>(CheckFlags::DEST)){
            if (prev_print == 1){
                std::cout << ",";
            }
            std::cout << "DEST";
            prev_print = 1;
        }
        std::cout << "]";
    }
    
}
