#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <deque>

using namespace std;
#define int int64_t
using vi = vector<int>;

unordered_map<int, int> prv;
unordered_map<int, int> nxt;
vector<pair<int, int>> nxt_prv;
vi a;

bool calc(int l, int r) {
    deque<pair<int, int>> pairs_to_solve;
    pairs_to_solve.push_back({l, r});
    while (!pairs_to_solve.empty()) {
        auto p = pairs_to_solve.back();
        pairs_to_solve.pop_back();
        int l = p.first, r = p.second;
        if (l >= r - 1) continue;
        int m = (r + l) / 2;
        bool smth_changed = false;
        for (int i = 0; i != (r - l) / 2; ++i) {
            if (nxt_prv.at(m - i).first < l && nxt_prv.at(m - i).second >= r) {
                pairs_to_solve.push_back({l, m - i});
                pairs_to_solve.push_back({m - i + 1, r});
                smth_changed = true;
                break;
            }
            int ind = m + i;
            if (nxt_prv.at(ind).first < l && nxt_prv.at(ind).second >= r) {
                pairs_to_solve.push_back({l, ind});
                pairs_to_solve.push_back({ind + 1, r});
                smth_changed = true;
                break;
            }
        }
        if (!smth_changed) return false;
    }
    return true;
}

void solve() {
    prv.clear();
    nxt.clear();
    nxt_prv.clear();
    a.clear();
    int n; cin >> n;
    a.resize(n);
    nxt_prv.resize(n);
    for (int i = 0; i != n; ++i) {
        cin >> a.at(i);
        if (prv.count(a.at(i)) != 0) nxt_prv.at(i).first = prv.at(a.at(i));
        else nxt_prv.at(i).first = -1;
        prv[a.at(i)] = i;
    }    
    for (int i = n - 1; i >= 0; --i) {
        if (nxt.count(a.at(i)) != 0) nxt_prv.at(i).second = nxt.at(a.at(i));
        else nxt_prv.at(i).second = n + 1;
        nxt[a.at(i)] = i;
    }
    cout << (calc(0, n) ? "non-boring" : "boring") << '\n';
}

signed main() {
    int t; cin >> t;
    for (int i = 0; i != t; ++i) solve();
}
