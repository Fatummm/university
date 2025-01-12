#include <iostream>
#include <vector>


#define SEPARATOR ' '
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
    for (size_t i = 0; i != v.size(); ++i) {
        in >> v[i];
    }
    return in;
}


int main() {
    ll n; std::cin >> n;
    std::vector<ll> v(n);
    for (size_t i = 0; i != v.size(); ++i) {
        ll x; std::cin >> x;
        v[x - 1] = i + 1;
    }
    std::cout << v;
}