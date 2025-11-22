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
    int n, m; cin >> n >> m;
    vector<hs> pw(6 * 1e5);
    pw[0] = {1, 1};
    rep(i, pw.size() - 1) {
        pw[i + 1] = pw[i] * BASE;
    }

    map<int, set<hs>> hashes;
    rep(i, n) {
        string s; cin >> s;
        vector<hs> sh(s.size() + 1, {0, 0});
        rep(i, s.size()) {
            sh[i+1] = sh[i] * BASE + (s[i] - 'a' + 1);
        }
        hashes[s.size()].insert(sh.back());
    }

    rep(i, m) {
        string s; cin >> s;
        // if no such length
        if (hashes.find(s.size()) == hashes.end()) {
            cout << "NO\n";
            continue;
        }
        vector<hs> sh(s.size() + 1, {0, 0});
        rep(i, s.size()) {
            sh[i+1] = sh[i] * BASE + (s[i] - 'a' + 1);
        }
        bool flag = false;
        rep(i, s.size()) {
            int c = (s[i] - 'a' + 1);
            hs tmp = sh.back() - pw[s.size() - 1 - i] * c;
            rep(j, 2) {
                c = (c + 1) % 3 + 1;
                if (hashes[s.size()].find(tmp + pw[s.size() - 1 - i] * c) != hashes[s.size()].end()) {
                    cout << "YES\n";
                    flag = true;
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (!flag) cout << "NO\n";
    }
}

signed main() {
    solve();
}