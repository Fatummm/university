#include <iostream>
#include <string>
#include <set>
#include <vector>

std::vector<std::string> Split(std::string& line) {
    std::vector<std::string> words;
    std::string word = "";
    for (const char elem: line) {
        if (elem == '/') {
            words.push_back(word + '/');
        }
        word += elem;
    }
    return words;
}

int main() {
    std::set<std::string> dirs;
    std::string line;
    while (std::cin >> line) {
        std::vector<std::string> v = Split(line);
        for (std::string& elem: v) {
            dirs.insert(elem);
        }
    }
    for (std::string s: dirs) {
        std::cout << s << '\n';
    }
}