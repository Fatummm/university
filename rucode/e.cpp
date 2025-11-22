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
    int n, m; cin >> n >> m;
    int dmin, dmax;
    if (n * (n-1) / 2 < m) {
        cout << -1 << '\n';
        return;
    }
    if (m >= n) dmin = 1;
    else dmin = n - m;

    int k;
    for (k = 1; k < n; ++k) {
        if (k * (k-1) / 2 >= m) break;
    }
    cout << dmin << ' ' << n - k + 1 << '\n';
}

signed main() {
    int t = 1;
    //cin >> t;
    while (t--) solve();
}