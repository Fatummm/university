#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

#define int int64_t
using vi = vector<int>;

signed main() {
    int n, x, y; cin >> n >> x >> y;
    vi v(n);
    for (int i = 0; i != n; ++i) cin >> v[i];
    if (x > y) {
        cout << n << '\n';
        return 0;
    }
    int steps = 0;
    int broken = 0;
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; --i) {
        if (v[i] <= x) {
            if (steps * y + v[i] <= x) {
                ++steps;
                ++broken;
            }
            else {
                
            }
        }
    }
}