#include <iostream>
#include <map>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::map<std::string, uint64_t> mp;
    uint64_t k; std::cin >> k;
    std::string word;
    while (std::cin >> word) {
        ++mp[word];
    }
    std::vector<std::pair<std::string, uint64_t>> v(mp.begin(), mp.end());
    std::sort(v.begin(), v.end(), []
    (std::pair<std::string, uint64_t> lhs, std::pair<std::string, uint64_t> rhs){
        return std::tie(rhs.second, lhs.first) < std::tie(lhs.second, rhs.first);
    });
    for (uint64_t i = 0; i != std::min(k, v.size()); ++i) {
        std::cout << v.at(i).first << '\t' << v.at(i).second << '\n';
    }
}