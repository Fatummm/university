#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>
#define int int64_t
#define uint uint64_t
#define ll long long


int multiplie(int a, int b, int mod) {
    a = a % mod;
    long long res = 0;
    while (b > 0) {
        if (b % 2 == 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return res;
}

int powpow(int a, int b, int mod) {
    long long res = 1;
    a = a % mod; 
    while (b > 0) {
        if (b % 2 == 1)
            res = multiplie(a, res, mod);
        a = multiplie(a, a, mod);
        b /= 2;  
    }
    return res;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

std::vector<int> extended_euclid(int a, int b) {
    if (b == 0) return {a, 1, 0};
    int dn, xn, yn;
    std::vector<int> v = extended_euclid(b, a % b); dn = v[0], xn = v[1], yn = v[2];
    int d = dn, x = yn, y = xn - (a / b) * yn;
    return {d, x, y}; 
}

signed main() {
    uint p, q, e_start; std::cin >> p >> q >> e_start;
    int phi = (p - 1) * (q - 1);
    int e, d;
    int n = p*q;
    for (int i = e_start; i != phi; ++i) {
        if (gcd(i, phi) == 1) {
            e = i;
            break;
        }
    }
    std::vector<int> vec = extended_euclid(e, phi);
    d = vec[1];
    while (d + phi < phi) d += phi;
    std::string s; std::cin >> s;
    std::cout << "Private: " << d << ' ' << n << '\n';
    std::cout << "Public: " << e << ' ' << n << '\n';
    std::cout << "Initial bytes: ";
    uint64_t msg = 0;
    
    for (int i = 0; i != s.size(); ++i) {
        msg *= 256;
        msg += int(s[i]);
        std::cout << int(s[i]) << ' ';
    }
    uint64_t encrypted = powpow(msg, e, n);
    std::vector<int> v;
    std::cout << "\nEncrypted bytes: ";
    while (encrypted != 0) {
        v.push_back(encrypted % 256);
        encrypted /= 256;
    }
    while (!v.empty()) {
        std::cout << v.back() << ' ';
        v.pop_back();
    }
    std::cout << '\n';
}