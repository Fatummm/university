#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
        if (*it == ' ') {
            s.erase(it--);
        }
    }
    std::string reversed(s.rbegin(), s.rend());
    if (s == reversed) std::cout << "YES\n";
    else std::cout << "NO\n";
}