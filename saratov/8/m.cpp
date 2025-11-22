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

#define MOD 998244353

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
    vector<int> a(n);
    vector<int> b(n);
    rep(i, n) {
        cin >> a[i];
        a[i] = a[i] * (n - i) * (i + 1);
    }
    rep(i, n) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int res = 0;
    rep(i, n) {
        res = res + ((a[i] % MOD) * (b[i] % MOD)) % MOD;
        res %= MOD;
    }
    cout << res << '\n';
}

signed main() {
    int t = 1;
    //cin >> t;
    while (t--) solve();
}