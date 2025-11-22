#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <deque>
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

void iostreamUntie() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

int bin_pow(int x, int y) {
    if (y <= 0) return 1;
    if (y % 2 == 0) return bin_pow(x*x, y/2);
    return x * bin_pow(x*x, y/2);
}

int find_pow(int n) {
    rep(i, 30) {
        if (bin_pow(3, i) == n) return i;
        if (bin_pow(3, i) > n) return i - 1;
    }
    return 0;
}

void solve() { // 30
    int ans = 0;
    int n; cin >> n;
    while (n) {
        int pw = find_pow(n);
        ans += (bin_pow(3, pw + 1) + pw * bin_pow(3, pw - 1));
        n -= bin_pow(3, pw);
    }
    cout << ans << '\n';
}

signed main() {
    iostreamUntie();
    int t = 1;
    cin >> t;
    while (t--) solve();
}