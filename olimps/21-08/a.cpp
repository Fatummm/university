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

void solve() {
    int n; cin >> n;
    deque<char> s1(n);
    rep(i, n) cin >> s1[i];
    cin >> n;
    string s2; cin >> s2;
    rep(i, n) {
        char c; cin >> c;
        if (c == 'D') {
            s1.push_back(s2[i]);
        } else s1.push_front(s2[i]);
    }
    rep(i, s1.size()) {
        cout << s1[i];
    }cout << '\n';
}

signed main() {
    iostreamUntie();
    int t = 1;
    cin >> t;
    while (t--) solve();
}