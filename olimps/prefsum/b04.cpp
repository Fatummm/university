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
    vi pref(n+1, 0);
    rep(i, n) {
        cin >> pref[i+1];
        pref[i+1] += pref[i];
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        auto it = lower_bound(pref.begin() + i, pref.end(), pref.back() - pref[i]);
        if (it != pref.end() && *it == pref.back() - pref[i]) mx = max(mx, pref[i]);
    }
    cout << mx << '\n';;
}

signed main() {
    iostreamUntie();
    int t = 1;
    //cin >> t;
    while (t--) solve();
}