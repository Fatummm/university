#include <iostream>
#include <string>
#include <vector>

std::string Join(const std::vector<std::string>& tokens, char delimiter) {
    std::string res;
    for (size_t i = 0; i != tokens.size(); ++i) {
        if (i != 0) res += delimiter;
        res += tokens[i];
    }
    return res;
}

int main() {
    std::cout << Join({"What", "is", "your", "name?"}, '_') << '\n';
}