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
using vi = vector<int>;
using vvi = vector<vector<int>>;

int bin_pow(int x, int y) {
    if (y <= 0) return 1;
    if (y % 2 == 0) return bin_pow(x*x, y/2);
    return x * bin_pow(x*x, y/2);
}

void iostreamUntie() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    int x = 0, y = 0;
    char c;
    while (cin >> c) {
        if (c == 'x') ++x;
        else ++y;
    }
    if (x > y) {
        rep(i, x-y) {
            cout << 'x';
        }
    }
    else {
        rep(i, y - x) {
            cout << 'y';
        }
    }
    cout << '\n';
}

signed main() {
    int t = 1;
    //cin >> t;
    while (t--) solve();
}