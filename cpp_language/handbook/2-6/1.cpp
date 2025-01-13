#include <iostream>
#include <vector>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
    int mx = -2147483647 - 1;
    std::pair<size_t, size_t> coords = {0, 0};
    for (size_t i = 0; i != matrix.size(); ++i) {
        for (size_t j = 0; j != matrix[i].size(); ++j) {
            if (mx < matrix[i][j] || (mx == matrix[i][j] && i + j < coords.first + coords.second)) {
                coords = {i, j};
                mx = matrix[i][j];
            }
        }
    }
    return coords;
}

int main() {
    size_t n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> mt(n, std::vector<int>(m));
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            std::cin >> mt[i][j];
        }
    }
    std::pair<size_t, size_t> ans = MatrixArgMax(mt);
    std::cout << ans.first << ' ' << ans.second << '\n';
}