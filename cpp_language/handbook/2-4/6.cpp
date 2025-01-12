#include <iostream>
#include <vector>

int main() {
    int m, n, k; std::cin >> m >> n >> k;
    std::vector<std::vector<char>> v(m, std::vector<char>(n, '0'));
    for (int i = 0; i != k; ++i) {
        int x, y; std::cin >> x >> y;
        v[--x][--y] = '*';
        for (int ii = std::max(0, x - 1); ii != std::min(x + 2, m); ++ii) {
            for (size_t jj = std::max(0, y - 1); jj != std::min(y + 2, n); ++jj) {
                //std::cout << ii << ' ' << jj << '\n';
                if (v[ii][jj] == '*') continue;
                v[ii][jj]++; 
            }
        }
    }
    for (int i = 0; i != m; ++i) {
        for (int j = 0; j != n; ++j) {
            if (j != 0) std::cout << ' ';
            std::cout << v[i][j];
        }
        std::cout << '\n';
    }
}