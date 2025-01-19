#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

std::string CommonPrefix(const std::vector<std::string>& words) {
    size_t min_size = std::numeric_limits<size_t>::max();

    for (size_t i = 0; i != words.size(); ++i) {
        min_size = std::min(min_size, words[i].size());
    }
    size_t length = 0;
    std::string prefix = "";
    for (size_t i = 1; i <= min_size; ++i) {
        prefix = words[0].substr(0, i);
        for (size_t j = 0; j != words.size(); ++j) {
            if (prefix != words[j].substr(0, i)) {
                return prefix.substr(0, prefix.size() - 1);
            }
        }
    }
    return prefix;
}

int main() {
    std::vector<std::string> v = {"good", "goal", "foooood"};
    std::cout << CommonPrefix(v) << '\n';
}