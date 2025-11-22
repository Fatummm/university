#include <vector>
#include <string>
#include <iostream>
#include <cstdint>

using namespace std;

#define int int64_t

int ceil(int x, int y) {
    if (x % y != 0) return x / y + 1;
    return x / y;
}

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    int x;
    for (int i = 0; i != n; ++i) {
        cin >> v[i];
        if (i != 0) v[i] += v[i - 1];
    }
    int mx = 0;
    int l = 0, r = 1;
    while (r < n) {
        mx = max(mx, v[r]-v[l]-k*ceil(r-l, m));
        if (v[l] > v[r]) l = r;
        ++r;
    }
    cout << mx << '\n';
}