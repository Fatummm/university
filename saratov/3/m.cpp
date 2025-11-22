#include <vector>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <set>
#include <iomanip>
#include <limits>
#include <deque>

using namespace std;

#define int int64_t
using vi = vector<int>;
using vvi = vector<vector<int>>;

void solve() {
    int n; cin >> n;
    deque<pair<int, int>> v(n);
    for (int i = 0; i != n; ++i) {
        int x; cin >> x;
        v[i] = {x, i};
    }
    sort(v.begin(), v.end());
    vector<pair<int, int>> ans;
    int markers = 1;
    int cnt = 0;
    while (v.size() != 0) {
        if (cnt == v[0].first) {
            ans.push_back(v[0]);
            v.pop_front();
            cnt = 1;
            ++markers;
            continue;
        }
        ans.push_back(v.back());
        v.pop_back();
        ++cnt;
    }
    for (int i = 0; i != ans.size(); ++i) {
        cout << ans[i].second + 1 << ' ';
    }
    cout << '\n';
}

signed main() {
    int t; cin >> t;
    for (int i = 0; i != t; ++i) solve(); 
}