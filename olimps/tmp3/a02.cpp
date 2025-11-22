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
    vector<int> even;
    vector<int> odd;
    rep(i, n) {
        int x; cin >> x;
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    rep(i, even.size()) cout << even[i] << ' ';
    rep(i, odd.size()) cout << odd[i] << ' ';
    cout << '\n';
}

signed main() {
    iostreamUntie();
    int t = 1;
    //cin >> t;
    while (t--) solve();
}