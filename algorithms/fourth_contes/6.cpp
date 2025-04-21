#include <iostream>
#include <cstdint>
#include <cmath>

bool is_prime(int x) {
    for (int i = 2; i != x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int64_t ext_pow(int64_t a, int64_t b, int64_t mod = INT64_MAX) {
    if (b == 1) return a % mod;
    if (b % 2 == 1) return (a * ext_pow(a*a % mod, b/2, mod)) % mod;
    return ext_pow(a*a % mod, b/2, mod) % mod;
}

int main() {
    int64_t n; std::cin >> n;
    int64_t const_n = n;
    int64_t miller_first = 0, miller_divisors = 0, miller_second = 0;
    n -= 1;
    int64_t s = 0;
    while (n % 2 == 0) {
        ++s;
        n/=2;
    }
    for (int i = 1; i != const_n; ++i) {
        if (i != 1 && const_n % i == 0) continue;
        else if (ext_pow(i, n, const_n) == 1) {
            miller_first++;
        }
        else {
            for (int r = 0; r != s; ++r) {
                if (ext_pow(ext_pow(i, n, const_n), pow(2, r), const_n) == const_n - 1) {
                    ++miller_second;
                    break;
                }
            }
        }
    }
    miller_divisors = const_n - 1 - miller_first - miller_second;
    //std::cout << miller_divisors << ' ' << miller_first << ' ' << miller_second << '\n';

    int64_t fermat_divisors, fermat_condition = 0;
    for (int i = 1; i != const_n; ++i) {
        if (ext_pow(i, const_n - 1, const_n) == 1) fermat_condition++;
    }
    fermat_divisors = const_n - 1 - fermat_condition;
    //std::cout << fermat_divisors << ' ' << fermat_condition << '\n';
    std::cout << "Miller-Rabin test: " << (miller_divisors == 0 ? "True " : "False ") << miller_divisors << ' '
    << miller_first << ' ' << miller_second << '\n';
    std::cout << "Fermat test: " << (fermat_divisors == 0 ? "True " : "False ") << fermat_divisors
    << ' ' << fermat_condition << '\n'; 
}