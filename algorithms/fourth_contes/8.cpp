#include <iostream>
#include <cstdint>

bool is_prime(int x) {
    for (int i = 2; i != x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n; std::cin >> n;
    int n_permanent = n;
    bool started = false;
    for (int i = 2; i <= n_permanent; ++i) {
        if (is_prime(i)) {
            while (n % i == 0 && n != 0) {
                if (started) std::cout << ' ';
                else started = true;
                std::cout << i;
                n /= i;
            }
        }
    }
}