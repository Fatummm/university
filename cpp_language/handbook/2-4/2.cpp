#include <iostream>
#include <string>


int main() {
    std::string s; std::cin >> s;
    for (std::string::iterator it = s.begin() + 1; it != s.end(); ++it) {
        switch (*it) { 
            case 'a': case 'e': case 'h': case 'i': 
            case 'o': case 'u': case 'w': case 'y': { 
                s.erase(it); it--;
            }
        }
    }
    
    for (std::string::iterator it = s.begin() + 1; it != s.end(); ++it) {
        switch (*it) {
            case 'b': case 'f': case 'p': case 'v': {
                *it = '1'; break;
            }
            case 'c': case 'g': case 'j': case 'k': case 'q': 
            case 's': case 'x': case 'z': {
                *it = '2'; break;
            }
            case 'd': case 't': {
                *it = '3'; break;
            }
            case 'l': {
                *it = '4'; break;
            }
            case 'm': case 'n': {
                *it = '5'; break;
            }
            case 'r': {
                *it = '6';
            }
        }
    }
    for (std::string::iterator it = s.begin() + 1; it != s.end(); ++it) {
        if (*it == *(it - 1)) {
            s.erase(it); --it;
        }
    }
    std::cout << s.substr(0, 4);
    for (int i = 0; i < 4 - (int)s.size(); ++i) {
        std::cout << '0';
    }
}