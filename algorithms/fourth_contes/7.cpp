#include <iostream>
#include <cstdint>
#include <vector>

bool is_prime(int x) {
    for (int i = 2; i != x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int64_t s, f; std::cin >> s >> f;
    std::vector<bool> v(f + 1, false);
    int cnt = 0;
    std::cout << "Start and finish: " << s << ' ' << f << '\n';
    for (int prime = 2; prime != f; ++prime) {
        if (is_prime(prime)) {
            ++cnt;
            int i = prime + prime;
            bool flag = false;
            while (i <= f) {
                if (i >= s && i <= f && !(v[i])) {
                    
                    if (flag) {
                        std::cout << ' ' << i;
                    }
                    else {
                        flag = true;
                        std::cout << "Iteration : " << cnt << '\n' << i;
                    }
                    v[i] = true;
                }
                i += prime;
            }
            if (flag) std::cout << '\n';
        }
    }
    bool flag = false;
    std::cout << "Primes :\n";
    for (int i = s; i <= f; ++i) {
        if (!v[i]) {
            if (!flag) std::cout << i;
            else std::cout << ' ' << i;
            flag = true;
        }
    }
    if (!flag) std::cout << "No primes";
    std::cout << '\n';
}