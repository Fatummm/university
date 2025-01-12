#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define SEPARATOR '\n'
#define ll long long

template <typename T>
std::ostream& operator << (std::ostream& out, std::vector<T>& v) {
    for (size_t i = 0; i != v.size(); ++i) {
        out << v.at(i) << SEPARATOR;
    }
    return out;
}

template <typename T>
std::istream& operator >> (std::istream& in, std::vector<T>& v) {
    if (v.size() == (size_t)0) {
        T value;
        while (std::getline(in, value)) {
            v.push_back(value);
        }
        return in;
    }
    for (size_t i = 0; i != v.size(); ++i) {
        in >> v[i];
    }
    return in;
}


int main() {
    std::vector<std::string> v;
    std::cin >> v;
    std::sort(v.rbegin(), v.rend());
    std::cout << v;
}