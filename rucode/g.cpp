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

int bin_pow(int x, int y) {
    if (y <= 0) return 1;
    if (y % 2 == 0) return bin_pow(x*x, y/2);
    return x * bin_pow(x*x, y/2);
}

void iostreamUntie() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    string z; cin >> z;
    string cotenated;
    vector<bool> v(1000, false);
    string tmp;
    while (cin >> tmp) {
        cotenated += tmp;
        v[cotenated.size() - tmp.size()] = true;
    }
    string forbidden(cotenated);
    for (int i = z.size(); i != cotenated.size(); ++i) {
        if (cotenated.substr(i-z.size(), z.size()) == z) {
            for (int j = i - z.size(); j != i; ++j) {
                forbidden[j] = 'x';
            }
        }
    }
    //from start to z.size()
    rep(i, z.size()-1) {
        if (forbidden[i] != 'x') continue;
        char start = '0';
        if (v[i] && !v[i+1]) start = '1';
        forbidden[i] = start;
    }

    for (int i = z.size() - 1; i != forbidden.size(); ++i) {
        if (forbidden[i] != 'x') continue;
        char start = '0';
        if (v[i] && !v[i+1]) start = '1';
        forbidden[i] = start;
        if (forbidden.substr(i + 1 - z.size(), z.size()) == z) forbidden[i]++;
    }
    for (int i = 0; i != forbidden.size(); ++i) {
        if (i != 0 && v[i]) cout << ' ';
        cout << forbidden[i];
    }
}

signed main() {
    int t = 1;
    //cin >> t;
    while (t--) solve();
}