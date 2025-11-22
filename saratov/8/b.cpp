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

char check(const vector<vector<char>>& v, int lx, int ly, int rx, int ry) {
    set<char> s;
    for (int i = lx; i != rx; ++i) {
        for (int j = ly; j != ry; ++j) {
            s.insert(v[i][j]);
        }
    }
    if (s.size() != 1) return '0';
    else return *s.begin();
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> v[i][j];
        }
    }
    set<char> ans;
    if (n % 3 == 0) {
        rep(i, 3) {
            char c = check(v, 0 + n/3 * i, 0, n/3 + n/3 * i, m);
            if (c != '0') ans.insert(c);
        }
    }
    if (ans.size() == 3) {
        cout << "YES\n";
        return;
    }
    ans.clear();
    if (m % 3 == 0) {
        rep(i, 3) {
            char c = check(v, 0, 0 + m/3 * i, n, m/3 + m/3 * i);
            if (c != '0') ans.insert(c);
        }
    }
    if (ans.size() != 3) cout << "NO\n";
    else cout << "YES\n";
}

signed main() {
    iostreamUntie();
    int t = 1;
    //cin >> t;
    while (t--) solve();
}