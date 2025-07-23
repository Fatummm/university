#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    for (int j = 0; j != t; ++j) {
        int n; std::cin >> n;
        long long operations = 0;
        long long a, b, c, d;
        for (int i = 0; i != n; ++i) {
            std::cin >> a >> b >> c >> d;
            if (a > c && b > d) operations += a + b - d;
            else if (a > c) operations += a - c;
            else if (b > d) operations += a + (b - d);
        }
        std::cout << operations << '\n';
    }
}