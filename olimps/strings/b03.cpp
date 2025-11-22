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
#include <deque>
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
    deque<char> s;
    char x;
    while (cin >> x) s.push_back(x);
    int a = 0, b = 0, c = 0;
    while (s.front() == 'a') {
        ++a;
        s.pop_front();
    }

    while (s.front() == 'b') {
        ++b;
        s.pop_front();
    }
    while (s.front() == 'c') {
        ++c;
        s.pop_front();
    }
    if (s.size() == 0 && a >= 1 && b >= 1 && (c == a || c == b)) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    int t = 1;
    //cin >> t;
    while (t--) solve();
}