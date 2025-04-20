#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>

std::vector<int> extended_euclid(int a, int b) {
    if (b == 0) return {a, 1, 0};
    int dn, xn, yn;
    std::vector<int> v = extended_euclid(b, a % b); dn = v[0], xn = v[1], yn = v[2];
    int d = dn, x = yn, y = xn - (a / b) * yn;
    return {d, x, y}; 
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool is_coprime(int a, int b) {
    return gcd(a, b) == 1;
}

int phi(int x) {
    int res = 0;
    for (int i = 1; i <= x; ++i) {
        res += int(is_coprime(i, x));
    }
    return res;
}

int zhoskiy_pow(int x, int y, int mod) {
    if (y == 1) return x;
    if (y % 2 == 1) return zhoskiy_pow(x*x % mod % 256, y/2, mod) * x % mod % 256;
    return zhoskiy_pow(x*x % mod % 256, y/2, mod) % mod % 256;
}

int main() {
    int p, q, e_start; std::cin >> p >> q >> e_start;
    int n = p * q;
    int func = (p - 1) * (q - 1);
    int e, d;
    for (int i = e_start; i != func; ++i) {
        if (is_coprime(i, func)) {
            e = i; break;
        }
    }
    std::vector<int> v = extended_euclid(func, e);
    d = v[2];
    while (d < 0) d += func;
    // for (int i = 1; i != func; ++i) {
    //     if (e * i % func == 1) {
    //         d = i; break;
    //     }
    // }
    std::string s; std::cin >> s;
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
        std::cout << int(zhoskiy_pow(int(s[i]), e, n));
    }
    std::cout << '\n';
}