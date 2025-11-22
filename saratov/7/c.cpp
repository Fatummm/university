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
    BASE = rnd() % int(5e7) + int(1e7);
    //BASE = 10;
    //cout << BASE << '\n';
    string a;
    string b;
    cin >> a >> b;
    b = b + b;
    set<hs> hashes_of_b;
    vector<hs> pw(a.size());
    pw[0] = {1, 1};
    for (int i = 1; i != pw.size(); ++i) {
        pw[i] = pw[i-1] * BASE;
    }
    vector<hs> b_hash(b.size() + 1);
    rep(i, b.size()) {
        b_hash[i + 1] = b_hash[i] + pw[i] * (b[i] - 'a' + 1);
        if (i + 1 >= b.size() / 2) {
            hashes_of_b.insert((b_hash[i + 1] - b_hash[i + 1 - b.size()/2]) * pw[int(a.size()) - b.size() / 2]);
        }
    }
    vector<hs> sh(a.size() + 1);
    vector<int> ans;
    int cnt = 0;
    cout << hashes_of_b.size() << " <- size\n";
    rep(i, a.size()) {
        sh[i + 1] = sh[i] + pw[i] * (a[i] - 'a' + 1);
        if (i + 1 < b.size() / 2) continue;
        hs s1 = (sh[i + 1] - sh[i + 1 - int(b.size() / 2)]) * pw[int(a.size()) - (i + 1)];
        cout << s1 << '\n';
        if (hashes_of_b.find(s1) != hashes_of_b.end()) {
            ++cnt;
            cout << i << '\n';
        }
    }
    cout << cnt;
    for (auto it = hashes_of_b.begin(); it != hashes_of_b.end(); ++it) {
        cout << *it << ' ';
    } cout << '\n';
}

signed main() {
    int t = 1; 
    //cin >> t;
    while (t--) solve();
}