#include <vector>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <set>
#include <iomanip>
#include <limits>

using namespace std;

#define int int64_t
using vi = vector<int>;
using vvi = vector<vector<int>>;

signed main() {
    int n, k; cin >> n >> k;
    vi v(n);
    vi pref(n + 1);
    for (int i = 0; i != n; ++i) {
        cin >> v[i];
        pref[i+1] = pref[i] + v[i];
    }
    sort(v.begin(), v.end());
    vvi dp(n + 1, vi(k+1, 0));
    for (int i = 2; i != n + 1; ++i) {
        for (int j = 1; j != i / 2; ++j) {
            dp[i][j] = dp[i-1][j];
            for (int ii = 2; ii <= j; ii += 2) {
                int tmp = 0;
                for (int l = 0; l != ii; ++l) {
                    if (l >= ii/2) tmp -= v[i-l];
                    else tmp += v[i-l];
                }
                dp[i][j] = max(dp[i][j], dp[i-ii][j-ii/2]+tmp);
                cout << tmp << "aSdasd\n";
            }
        }
    }
    for (int i = 0; i != dp.size(); ++i) {
        for (int j = 0; j != dp[i].size(); ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}