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
    vi v(n);
    rep(i, n) cin >> v[i];
    vi suff(n);
    suff.back() = v.back();
    for (int i = static_cast<int>(v.size()) - 2; i >= 0; --i) {
        suff[i] = min(suff[i + 1], v[i]);
    }
    vi ans(n);
    rep(i, n) {
        auto it = lower_bound(suff.begin() + i, suff.end(), v[i]);
        --it;
        ans[i] = max(it - suff.begin() - i - 1, static_cast<int>(-1));
    }

    rep(i, n) cout << ans[i] << ' ';
    cout << '\n';
}

signed main() {
    iostreamUntie();
    int t = 1;
    //cin >> t;
    while (t--) solve();
}