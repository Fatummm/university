#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>

using namespace std;

#define int int64_t
using vi = vector<int>;
using vvi = vector<vector<int>>;

#define FREE 0
#define BLOCKED 1
#define LAB 2
#define GOOD 3

int count_paths(const vvi& field, int x, int y) {
    int cnt = 0;
    for (int dx : {-1, 0, 1}) {
        for (int dy : {-1, 0, 1}) {
            if (abs(dx + dy) != 1) continue;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < field.size() && ny < field[0].size()) {
                if (field[nx][ny] == FREE) ++cnt;
            }
        }
    }
    //cout << x << ' ' << y << ' ' << cnt << '\n';
    return cnt;
}

void find_way(vvi& field, int x, int y) {
    if (x == field.size() || y == field[0].size() || x < 0 || y < 0) return;
    if (field[x][y] == BLOCKED || field[x][y] == GOOD) return;
    if (field[x][y] == LAB) {
        find_way(field, x + 1, y);
        find_way(field, x - 1, y);
        find_way(field, x, y + 1);
        find_way(field, x, y - 1);
        return;
    }
    if (count_paths(field, x, y) > 1) return;
    
    field[x][y] = GOOD;
    find_way(field, x + 1, y);
    find_way(field, x - 1, y);
    find_way(field, x, y + 1);
    find_way(field, x, y - 1);
}

void solve() {
    int n, m; cin >> n >> m;
    vvi field(n, vi(m));
    char c;
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            cin >> c;
            if (c == '.') field[i][j] = FREE;
            else if (c == '#') field[i][j] = BLOCKED;
            else if (c == 'L') field[i][j] = LAB;
        }
    }
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            if (field[i][j] == LAB) {
                find_way(field, i, j);
                break;
            }
        }
    }
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            if (field[i][j] == BLOCKED) cout << '#';
            else if (field[i][j] == FREE) cout << '.';
            else if (field[i][j] == GOOD) cout << '+';
            else if (field[i][j] == LAB) cout << 'L';
        }
        cout << '\n';
    }

}

signed main() {
    int t; cin >> t;
    for (int i = 0; i != t; ++i) solve();
}