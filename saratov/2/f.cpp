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
    vi ascending(n);
    vi descending(n);
    int x;
    for (int i = 0; i != n; ++i) {
        cin >> x; --x;
        v[i] = x;
        if (i != x) ascending[i] = 1;
        if (n - 1 - x != i) descending[i] = 1;
    }
    int a = 0, b = 0, c = 0;
    for (int i = 0; i != n; ++i) {
        if (ascending[i] == 1 && descending[i] == 1) {
            ++a;
            ++b;
            ++c;
        }
        else if (ascending[i] == 1) ++a;
        else if (descending[i] == 1) ++b;
    }
    if (a <= b - c) cout << "First\n";
    else if (b < a - c) cout << "Second\n";
    else cout << "Tie\n";
}

signed main() {
    int t; cin >> t;
    for (int i = 0; i != t; ++i) solve(); 
}