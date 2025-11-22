#include <iostream>
#include <vector>

using namespace std;

signed main() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i != n; ++i) cin >> v[i];
    int cnt = 0;
    for (int i = 0; i != n; ++i) {
        if (v[i] > 0 && v[i] >= v[k-1]) ++cnt;
    }
    cout << cnt << '\n';
}
