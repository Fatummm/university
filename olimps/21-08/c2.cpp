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
    if (y <= 0) return 1;
    if (y % 2 == 0) return bin_pow(x*x, y/2);
    return x * bin_pow(x*x, y/2);
}

int find_pow(int n) {
    rep(i, 30) {
        if (bin_pow(3, i) == n) return i;
        if (bin_pow(3, i) > n) return i - 1;
    }
    return 0;
}

void solve() { // 30
    int n, k; cin >> n >> k;
    vector<int> number;
    while (n) {
        number.push_back(n % 3);
        k -= n % 3;
        n /= 3;
    }
    //reverse(number.begin(), number.end());
    if (k < 0) {
        cout << -1 << '\n';
        return;
    }

    while (number.size() > 1 && k >= 2) {
        int mx = min(k/2, number.back());
        number.back() -= mx;
        number[number.size() - 2] += 3 * mx;
        if (number.back() == 0) number.pop_back();
        k -= mx*2;
    }
    // cout << "number:";
    // rep(i, number.size()) cout << number[i];
    // cout << '\n';
    int res = 0;
    rep(i, number.size()) {
        res += number[i] * (bin_pow(3, i+1) + i * bin_pow(3, i-1));
    }
    cout << res << '\n';
}

signed main() {
    iostreamUntie();
    int t = 1;
    cin >> t;
    while (t--) solve();
}