#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <cmath>

using namespace std;
#define int int64_t
#define rep(i, n) for (int i = 0; i != n; ++i)

using vi = vector<int>;

int count_ones(int n, int m) {
    return n * n - (n / m) * (n / m);
}

void solve() {
    int x; cin >> x;
    for (int n = sqrt(x); n != 1e5; ++n) {
        int l = 1, r = n;
        int mid;
        while (r >= l) {
            //cout << l << ' ' << r << '\n';
            mid = (r+l)/2;
            int res = count_ones(n, mid);
            if (res > x){
                r = mid - 1;
            } else if (res == x) {
                cout << n << ' ' << mid << '\n';
                return;
            } else l = mid + 1;
        }
    }
    cout << -1 << '\n';
}

signed main() {
    int t; cin >> t;
    rep(i, t) solve();
}