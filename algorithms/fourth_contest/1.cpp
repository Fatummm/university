#include <iostream>
#include <cstdint>
#include <cmath>

int64_t gcd(int64_t a, int64_t b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool is_coprime(int64_t a, int64_t b) {
    return gcd(a, b) == 1;
}

int64_t phi(int64_t x) {
    int64_t res = 0;
    for (int i = 1; i <= x; ++i) {
        res += int(is_coprime(i, x));
    }
    return res;
}

int main() {
    int64_t p, q, e_start; std::cin >> p >> q >> e_start;
    int64_t n = p * q;
    int64_t func = phi(n);
    int64_t e, d;
    for (int i = e_start; i != func; ++i) {
        if (is_coprime(i, func)) {
            e = i; break;
        }
    }
    for (int i = 1; i != func; ++i) {
        if (e * i % func == 1) {
            d = i; break;
        }
    }
    std::string s; std::getline(std::cin, s);
    std::cout << "Private: " << d << ' ' << n << '\n';
    std::cout << "Public: " << e << ' ' << n << '\n';
    std::cout << "Initial bytes: ";
    for (int i = 0; i != s.size(); ++i) {
        if (i != 0) std::cout << ' ';
        std::cout << int(s[i]);
    }
    std::cout << '\n';
    std::cout << "Encrypted bytes: ";
    for (int i = 0; i != s.size(); ++i) {
        if (i != 0) std::cout << ' ';
        std::cout << int64_t(pow(int64_t(s[i]), e)) % n;
    }
    std::cout << '\n';
}