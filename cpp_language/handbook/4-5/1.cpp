#include "address.h"
#include <iostream>
#include <string>

int main() {
    std::string line;
    Address address;
    while (getline(std::cin, line)) {
        try {
            Parse(line, &address);
            Unify(&address);
            std::cout << Format(*address) << "\n";
        } catch (...) {
            std::cout << "exception\n";
        }
    }
}