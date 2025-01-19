#include <iostream>
#include <set>
#include <cstdint>

int main() {
    std::set<int64_t> freq;
    int64_t num;
    while (std::cin >> num) {
        if (freq.find(num) == freq.end()) {
            freq.insert(num);
            std::cout << "NO" << std::endl;
        }
        else {
            std::cout << "YES" << std::endl;
        }
    }
}