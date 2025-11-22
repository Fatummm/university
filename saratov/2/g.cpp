#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

#define int int64_t
using vi = vector<int>;

void solve() {
    int n; cin >> n;
    vi v(n);
    int s = 0;
    for (int i = 0; i != n; ++i) {
        cin >> v[i];
        s ^= v[i];
    }
    if (s == 0) {
        cout << -1 << '\n';
        return;
    }
    int shift = 0;
    while(s >> (shift + 1) > 0) {
        ++shift;
    }
    for (int i = 0; i != n; ++i) {
        if (v[i] >> shift & 1) {
            int x = v[i] ^ s;
            cout << i + 1 << ' ' << v[i] - x << '\n';
            break;
        }
    }
}

signed main() {
    int t; cin >> t;
    for (int i = 0; i != t; ++i) solve(); 
}