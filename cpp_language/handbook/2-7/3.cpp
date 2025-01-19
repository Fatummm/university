#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> s;
    size_t last_index = 0;
    for (size_t i = 0; i != str.size(); ++i) {
        if (str[i] == delimiter) {
            s.push_back(str.substr(last_index, i - last_index));
            last_index = i + 1;
        }
        if (i == str.size() - 1) {
            s.push_back(str.substr(last_index));
        }
    }
    return s;
}

// int main() {
//     std::string s = "13-24--08-11-2014";
//     char c = '-';
//     std::vector<std::string> ans = Split(s, c);
//     for (size_t i = 0; i != ans.size(); ++i) {
//         std::cout << ans[i] << '\n';
//     }

// }