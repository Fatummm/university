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

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void iostreamUntie() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    set<int> ans = {0};
    map<int, uint64_t> mp;
    int cur = 0;
    rep(i, n) mp[v[i]] = rnd();
    rep(i, n) {
        cur ^= mp[v[i]];
        ans.insert(cur);
    }
    cout << ans.size() << '\n';
}

signed main() {
    iostreamUntie();
    int t = 1;
    //cin >> t;
    while (t--) solve();
}