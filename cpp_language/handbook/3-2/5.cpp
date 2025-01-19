#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>

// Сначала записываем в map
// Потом копируем в вектор и сортируем с компаратором

int main() {
    uint64_t m; uint64_t n; std::cin >> m >> n;
    std::map<std::string, uint64_t> freq;
    std::string word;
    for (uint64_t i = 0; i != m; ++i) {
        std::cin >> word;
        for (uint64_t i = 0; i + n <= word.size(); ++i) {
            ++freq[word.substr(i, n)];
        }
    }
    std::cout << freq.size() << std::endl;
    std::vector<std::pair<std::string, uint64_t>> v(freq.begin(), freq.end());
    std::sort(v.begin(), v.end(), [](std::pair<std::string, uint64_t>& lhs, std::pair<std::string, uint64_t>& rhs){
        return std::tie(rhs.second, lhs.first) < std::tie(lhs.second, rhs.first);
    });
    
    for (const auto& [word, fr]: v) {
        std::cout << word << " - " << fr << std::endl;
    }
    const char c[4] = "123";
}