#include <iostream>
#include <set>
#include <map>
#include <cstdint>
#include <string>

int main() {
    std::map<uint64_t, std::set<std::string>> pages;
    uint64_t n; std::cin >> n;
    std::string word;
    uint64_t page;
    for (uint64_t i = 0; i != n; ++i) {
        std::cin >> word >> page;
        pages[page].insert(word);
    }
    for (const auto& [page, words]: pages) {
        std::cout << page;
        for (std::string s: words) {
            std::cout << ' '<< s; 
        }
        std::cout << std::endl; 
    }
}