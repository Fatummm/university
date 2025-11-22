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

const int MOD1 = 1e9+7;
const int MOD2 = 1e9+9;
int BASE;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct hs {
    int x;
    int y;
};

bool operator == (const hs& lhs, const hs& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator < (const hs& lhs, const hs& rhs) {
    return (lhs.x == rhs.x ? lhs.y < rhs.y : lhs.x < rhs.x);
}

hs operator * (const hs& lhs, const hs& rhs) {
    hs c = {lhs.x * rhs.x % MOD1, lhs.y * rhs.y % MOD2};
    return c;
}

hs operator + (const hs& lhs, const hs& rhs) {
    hs result = {lhs.x + rhs.x, lhs.y + rhs.y};
    if (result.x >= MOD1) result.x -= MOD1;
    if (result.y >= MOD2) result.y -= MOD2;
    return result;
}

hs operator +(hs lhs, int x) {
    lhs.x += x; lhs.y += x;
    if (lhs.x >= MOD1) lhs.x -= MOD1;
    if (lhs.y >= MOD2) lhs.y -= MOD2;
    return lhs;
}

hs operator * (const hs& a, int b) {
    hs res = {a.x * b % MOD1, a.y * b % MOD2};
    return res;
}

ostream& operator << (ostream& out, const hs& a) {
    return out << '(' << a.x << ", " << a.y << ')';
}

hs operator - (const hs& lhs, const hs& rhs) {
    hs result = {lhs.x + MOD1 - rhs.x, lhs.y + MOD2 - rhs.y};
    if (result.x >= MOD1) result.x -= MOD1;
    if (result.y >= MOD2) result.y -= MOD2;
    return result;
}

void solve() {
    BASE = rnd() % int(5e4) + int(1e4);
    //BASE = 10;
    //cout << BASE << '\n';
    string pattern = "kk";
    string s = "avcjsususfkksus";
    vector<hs> pw(s.size());
    pw[0] = {1, 1};
    for (int i = 1; i != s.size(); ++i) {
        pw[i] = pw[i-1] * BASE;
    }
    vector<hs> pattern_hash(pattern.size() + 1);
    rep(i, pattern.size()) {
        pattern_hash[i + 1] = pattern_hash[i] * BASE + (pattern[i] - 'a' + 1);
    }
    vector<hs> sh(s.size() + 1);
    rep(i, s.size()) {
        sh[i + 1] = sh[i] + pw[i] * (s[i] - 'a' + 1);
        if (i + 1 < pattern.size()) continue;
        hs s1 = (sh[i + 1] - sh[i + 1 - pattern.size()]) * pw[s.size() - (i + 1)];
        hs s2 = pattern_hash.back() * pw[s.size() - pattern.size()];
        // cout << "current_pair: " << s1 << s2 << " symbol: " << s[i] << '\n';
        if (s1 == s2) cout  << i << '\n';
    }
    // cout << "pattern hash: ";
    // rep(i, pattern_hash.size()) {
    //     cout << pattern_hash[i] << ' ';
    // }
    // cout << "\nstring hash: ";
    // rep(i, s.size()+1) {
    //     cout << sh[i] << ' ';
    // }
    // cout << '\n';
}

signed main() {
    int t = 1; 
    //cin >> t;
    while (t--) solve();
}