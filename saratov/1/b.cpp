#include <vector>
#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

signed main() {
    int n; cin >> n;
    int s = 0;
    int x;
    for (int i = 0; i != n; ++i) {
        cin >> x; s += x;
    }
    int m; cin >> m;
    int ans = -1;
    int l, r;
    for (int i = 0; i != m; ++i) {
        cin >> l >> r;
        if (ans != -1) continue;
        if (l <= s && s <= r) ans = s;
        else if (l >= s) ans = l;
    }
    if (ans == -1) cout << -1 << '\n';
    else cout << ans << '\n';
}