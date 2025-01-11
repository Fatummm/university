#include <iostream>
#include <cstdint>

int main() {
    uint64_t n; std::cin >> n;
    uint64_t sm = 0;
    while (n) {
        sm += n % 10;
        n /= 10;
    }
    std::cout << sm;
}