#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;
#define int int64_t
#define rep(i, n) for (int i = 0; i != n; ++i)

void solve() {
    int n, m, k; cin >> n >> m >> k;
    if (k < max(abs(n), abs(m))) {
        cout << -1 << '\n';
        return;
    }
    int ans;
    if ((n + m) % 2 == 0) {
        k -= (min(abs(n), abs(m)) - 1);
        ans = (min(abs(n), abs(m)) - 1);
        ans += k - 2 * (k % 2 == 0);
    }
    else ans = k - 1;
    cout << ans << '\n';
}


signed main() {
    int t; cin >> t;
    rep(i, t) solve();
}