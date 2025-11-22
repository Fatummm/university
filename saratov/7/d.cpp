#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include <random>
#include <chrono>

#define int int64_t
#define rep(i, n) for (int i = 0; i != n; ++ i)
using namespace std;

const int MOD1 = 1e9+7;
const int MOD2 = 1e9+9;
int BASE;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct hs {
    int x;
    int y;
};

bool operator == (const hs& lhs, const hs& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator < (const hs& lhs, const hs& rhs) {
    return (lhs.x == rhs.x ? lhs.y < rhs.y : lhs.x < rhs.x);
}

hs operator * (const hs& lhs, const hs& rhs) {
    hs c = {lhs.x * rhs.x % MOD1, lhs.y * rhs.y % MOD2};
    return c;
}

hs operator + (const hs& lhs, const hs& rhs) {
    hs result = {lhs.x + rhs.x, lhs.y + rhs.y};
    if (result.x >= MOD1) result.x -= MOD1;
    if (result.y >= MOD2) result.y -= MOD2;
    return result;
}

hs operator +(hs lhs, int x) {
    lhs.x += x; lhs.y += x;
    if (lhs.x >= MOD1) lhs.x -= MOD1;
    if (lhs.y >= MOD2) lhs.y -= MOD2;
    return lhs;
}

hs operator * (const hs& a, int b) {
    hs res = {a.x * b % MOD1, a.y * b % MOD2};
    return res;
}

ostream& operator << (ostream& out, const hs& a) {
    return out << '(' << a.x << ", " << a.y << ')';
}

hs operator - (const hs& lhs, const hs& rhs) {
    hs result = {lhs.x + MOD1 - rhs.x, lhs.y + MOD2 - rhs.y};
    if (result.x >= MOD1) result.x -= MOD1;
    if (result.y >= MOD2) result.y -= MOD2;
    return result;
}

template <typename T>
struct PrefixSum2D {
public:
    PrefixSum2D(size_t n, size_t m, const std::vector<vector<T>>& table): data(n+1, std::vector<T>(m+1)) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                data[i+1][j+1] = data[i+1][j] + data[i][j+1] - data[i][j] + table[i][j];
            }
        }
    }

    void Print(std::ostream& out = std::cout) {
        for (int i = 0; i != data.size(); ++i) {
            for (int j = 0; j != data[i].size(); ++j) {
                out << data[i][j] << ' '; 
            }
            out << '\n';
        }
    }

    T get(int x, int y, int height = -1, int width = -1) {
        if (height == -1 || width == -1) return data[x][y];
        return data[x][y] - data[x-height][y] - data[x][y-width] + data[x-height][y-width];
    }
private:
    std::vector<std::vector<T>> data;
};

void solve() {
    BASE = rnd() % int(5e7) + int(1e7);
    int H, W, h, w; cin >> H >> W;
    vector<hs> pw(H * W, {1, 1}); // 2e6
    rep(i, pw.size() - 1) pw[i+1] = pw[i] * BASE; // 2e6
    vector<vector<hs>> hashes(H, vector<hs>(W)); // 2e6
    for (int i = 0; i != H; ++i) {
        for (int j = 0; j != W; ++j) {
            char c; cin >> c;
            c = c - 'a' + 1;
            if (i == 0 && j == 0) hashes[i][j] = hs{1, 1} * c;
            else if (j == 0) hashes[i][j] = hashes[i-1][W-1] + pw[i * W + j] * c;
            else hashes[i][j] = hashes[i][j] = hashes[i][j-1] + 1;
            hashes[i][j] = pw[i * W + j] * c;
        }
    } // 2e6
    PrefixSum2D<hs> pref1(H, W, hashes); // 2e6

    cin >> h >> w;
    hs needed = {0, 0};
    for (int i = 0; i != h; ++i) {
        for (int j = 0; j != w; ++j) {
            char c; cin >> c;
            c = c - 'a' + 1;
            if (i == 0 && j == 0) needed = hs{1, 1} * c;
            else needed = needed + pw[i * W + j] * c;
        }
    } // 2e6
    needed = needed * pw[(H - h) * W + (W - w)];
    int cnt = 0;
    for (int i =  h; i != H + 1; ++i) {
        for (int j = w; j != W + 1; ++j) {
            if (needed == pref1.get(i, j, h, w) * pw[(H-i)*W + (W - j)]) {
                ++cnt;
            }
        }
    } // 2e6
    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}