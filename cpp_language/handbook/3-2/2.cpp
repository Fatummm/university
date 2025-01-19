#include <iostream>
#include <map>
#include <string>
#include <cstdint>
#include <set>

int main() {
    std::map<char, uint64_t> letters;
    std::string word;
    uint64_t counter = 0;
    while (std::cin >> word) {
        std::set<char> tmp_letters;
        for (const char elem: word) {
            tmp_letters.insert(elem);
        }
        for (const char elem: tmp_letters) {
            ++letters[elem];
        }
        ++counter;
    }
    for (const auto& [elem, freq]: letters) {
        if (freq == counter) {
            std::cout << elem;
        }
    }
    std::cout << '\n';
}