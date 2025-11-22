#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;
#define int int64_t
#define rep(i, n) for (int i = 0; i != n; ++i)

using vi = vector<int>;

int f(int x) {
    if (x < 10) return x;
    return x % 10 + f(x / 10);
}

signed main() {
    int n; cin >> n;
    vi v(n);
    rep(i, n) cin >> v[i];
    vi ans(n);
    rep(i, n) {
        for (int j = i; j != n; ++j) {
            ans[i] += f(v[i] + v[j]);
            if (j != i) ans[j] += f(v[i] + v[j]);
        }
    }
    rep(i, n) cout << ans[i] << ' ';
    cout << '\n';
}