#include <iostream>
#include <vector>
#include <cstdint>

#define int int64_t

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

signed main() {
    int n; cin >> n;
    vector<int> v(n);
    int cur_gcd = 1;
    for (int i = 0; i != n; ++i) {
        cin >> v[i];
        if (i == 0) cur_gcd = v[i];
        else cur_gcd = gcd(cur_gcd, v[i]);
    }

    for (int i = 0; i != n; ++i) {
        if (cur_gcd == v[i] || cur_gcd % v[i] == 0) {
            cout << v[i] << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
