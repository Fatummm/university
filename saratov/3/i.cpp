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

void solve() {
    int n; cin >> n;
    vi v(n);
    for (int i = 0; i != n; ++i) cin >> v[i];
    int deleted = 0;
    bool win = true;
    for (int i = 1; i != n; ++i) {
        if (v[i] > v[i-1]) continue;
        if (v[i] == v[i-1]) {++v[i]; continue;}
        if (i >= 2 && v[i] <= v[i-2] && deleted == 0) {deleted = 1; v[i] = v[i-1]; continue;}
        if (i >= 2 && v[i] <= v[i-2]) {win = false; break;}
        if ()
    }
}

signed main() {

}