#include <iostream>
#include <vector>
#include <cstdint>
#define ll int64_t
#define ull uint64_t

ll d[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool dfs(std::vector<std::vector<ll>>& field, std::vector<bool>& visited, ll x, ll y, int cnt) {
    if (cnt == field.size() * field.size()) {
        for (int i = 0; i != field.size()*field.size(); ++i) {
            if (!visited[i]) return false;
        }
        return true;
    }
    for (auto [dx, dy]: d) {
        ll new_x = dx + x, new_y = dy + y;
        if (new_x < field.size() && new_x >= 0 && new_y < field.size() && new_y >= 0) {
            if (!visited[new_x*field.size() + new_y]) {
                visited[new_x*field.size() + new_y] = true;
                field[new_x][new_y] = cnt;
                if (dfs(field, visited, new_x, new_y, cnt+1)) return true;
                visited[new_x*field.size() + new_y] = false;
            }
        }
    }
    return false;
}

bool find_gay(std::vector<std::vector<ll>>& f, ll x, ll y) {
    std::vector<bool> visited(f.size()*f.size(), false);
    int cnt = 1;
    f[x][y] = 0;
    visited[x*f.size() + y] = true;
    return dfs(f, visited, x, y, cnt);
}

int main() {
    std::vector<std::vector<ll>> field;
    ll n; std::cin >> n;
    ll x, y; std::cin >> x >> y;
    field.resize(n); for (int i = 0; i != n; ++i) field[i].resize(n);
    std::cout << "Graph:\n";
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            std::cout << i*n + j << " - ";
            for (auto [dx, dy]: d) {
                if (dx + i < n && dx + i >= 0 && dy + j < n && dy + j >= 0) {
                    std::cout << (dx+i)*n + (dy+j) << ' ';
                }
                
            }
            std::cout << '\n';
        }
    }
    std::cout << "Hamiltonian path:\n";
    if (find_gay(field, x, y)) {
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != n; ++j) {
                if (j != 0) std::cout << ' ';
                std::cout << field[i][j];
            }
            std::cout << '\n';
        }
    }
    else std::cout << "No way\n";
}