#include <iostream>

int main() {
    int t; std::cin >> t;
    for (int i = 0; i != t; ++i) {
    int n, m; std::cin >> n >> m;
    if ((n <= 2 && m <= 2) || (n == 1) || (m == 1)) std::cout << "NO" << '\n';
    else std::cout << "YES" << '\n';
    }
}