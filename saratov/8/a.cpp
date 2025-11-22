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

void iostreamUntie() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    int n; cin >> n;
    vi a(n);
    vi b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    int res = 0;
    rep(i, n) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        if (i != 0) res += abs(a[i] - a[i-1]) + abs(b[i] - b[i-1]);
    }
    cout << res << '\n';
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}