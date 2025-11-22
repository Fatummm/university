#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define int int64_t
using namespace std;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> v(n);
    for (int i = 0; i != n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int index = upper_bound(v.begin(), v.end(), c) - v.begin();
    int cnt = 0;
    int step = 1;
    while (index > 0) {
        --index;
        if (c >= step * v[index]) {
            cnt++;
            step *= 2;
        }
    }
    cout << n - cnt << '\n';
}

signed main() {
    int t; cin >> t;
    for (int i = 0; i != t; ++i) solve();
}
