#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
//#define int int64_t
#define rep(i, n) for (int i = 0; i != n; ++i)

using vi = vector<int>;

set<int> pows;

int bin_pow(int x, int y) {
    if (y == 0) return 1;
    if (y == -1) return 0;
    if (y == 1) return x;
    if (y % 2 == 1) return x * bin_pow(x * x, y / 2);
    return bin_pow(x * x, y / 2);
}

void solve() {
    int mn = INT32_MAX;
    int n; cin >> n;
    vi a(n); 
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i != n + 1; ++i) {
        if (i != 0 && i != n && a[i-1] == a[i]) {
            auto iter = upper_bound(a.begin(), a.end(), a[i]);
            i = iter - a.begin();
        }
        int x;
        x = (i == n ? a[i-1] + 1 : a[i]);
        for (int pw = -1; pw <= log2(n-i) + 2; ++pw) {
            int count = bin_pow(2, pw);
            if (i + count != 0 && i+count < n && a[i + count - 1] == a[i + count]) {
                count = (upper_bound(a.begin(), a.end(), a[i + count]) - a.begin()) - i;
            }
            int y;
            if (i + count >= n) y = a.back() + 2;
            else y = a[i + count];
            if (x >= y) continue;
            mn = min(*pows.lower_bound(i) + *pows.lower_bound(count) + *pows.lower_bound(n - i - count), mn);
        }
    }
    cout << mn - n << '\n';
}

signed main() {
    rep(i, 30) {
        pows.insert(bin_pow(2, i));
    }
    int t; cin >> t;
    while (t--) solve();
}