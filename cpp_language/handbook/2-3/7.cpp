#include <iostream>
#include <cstdint>

int main() {
    uint64_t n; std::cin >> n;
    double sm = 0;
    for (int i = 1; i <= n; i += 2) {
        sm += 1.0/(i * 1.0);
    }
    for (int i = 2; i <=n; i += 2) {
        sm -= 1.0/(i * 1.0);
    }
    std::cout << sm;
}