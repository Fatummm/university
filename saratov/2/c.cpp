#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

#define int int64_t
using vi = vector<int>;

void solve() {
    int n; cin >> n;
    vi v(n);
    for (int i = 0; i != n; ++i) cin >> v[i];
    int winners = 1;
    int loser = -1;
    int minimum = v[0];
    for (int i = 1; i != n; ++i) {
        if (loser == -1 && v[i] > minimum) loser = v[i];
        else if (v[i] > loser) ++winners;
        else if (v[i] < loser && v[i] > minimum) loser = v[i];
        else if (v[i] < loser) winners++;
        minimum = min(minimum, v[i]);
    }
    cout << n - winners << '\n';
}

signed main() {
    int t; cin >> t;
    for (int i = 0; i != t; ++i) solve();
}