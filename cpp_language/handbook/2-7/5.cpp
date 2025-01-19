#include <iostream>
#include <vector>

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<int>> transposed(matrix[0].size(), std::vector<int>(matrix.size()));
    for (size_t i = 0; i != matrix.size(); ++i) {
        for (size_t j = 0; j != matrix[i].size(); ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main() {
    std::vector<std::vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    std::vector<std::vector<int>> s = Transpose(v);
    for (size_t i = 0; i != s.size(); ++i) {
        for (size_t j = 0; j != s[i].size(); ++j) {
            if (j != 0) std::cout << ' ';
            std::cout << s[i][j];
        }
        std::cout << '\n';
    }
}