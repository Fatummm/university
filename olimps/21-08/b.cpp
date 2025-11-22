#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <deque>
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

int bin_pow(int x, int y) {
    if (y == 0) return 1;
    if (y % 2 == 0) return bin_pow(x*x, y/2);
    return x * bin_pow(x*x, y/2);
}

void solve() {
    uint64_t n; cin >> n;
    vector<uint64_t> ans;
    for (int pw = 1; pw != 20; ++pw) {
        int current_pow = bin_pow(10, pw) + 1;
        if (n % current_pow == 0) ans.push_back(n / current_pow);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    rep(i, ans.size()) {
        if (i != 0) cout << ' ';
        cout << ans[i];
        if (i + 1 == ans.size()) cout << '\n';
    }
}

signed main() {
    iostreamUntie();
    int t = 1;
    cin >> t;
    while (t--) solve();
}