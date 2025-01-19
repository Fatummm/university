#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

int main() {
    uint64_t n, k; std::cin >> n >> k;
    std::vector<int64_t> v(n);
    std::vector<int64_t> vk(k);
    for (uint64_t i = 0; i != n; ++i) {
        std::cin >> v.at(i);
    }
    for(uint64_t i = 0; i != k; ++i) {
        std::cin >> vk.at(i);
    }
    for (uint64_t i = 0; i != k; ++i) {
        std::vector<int64_t>::iterator it = std::lower_bound(v.begin(), v.end(), vk.at(i));
        //std::cout << *it << '\n';
        std::vector<int64_t>::iterator prev = std::prev(it);
        if (it == v.end()) --it;
        else if (it != v.begin() && std::abs(*prev - vk.at(i)) <= (*it - vk.at(i))) --it;
        std::cout << *it << '\n';
    }
}