#include <iostream>
#include <vector>
#include <cstdint>

#define int int64_t

using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i != n; ++i) {
        int x; cin >> x;
        if (x <= 2) v[i] = x;
        else if (x % 2 == 0) v[i] = 2;
        else v[i] = 1;
    }
    bool flag = true;
    for (int i = 0; i != n; ++i) {
        if (v[i] < 0 || (v[i] == 1 && i + 1 == n)) {
            flag = false;
            break;
        }
        if (v[i] == 1) {
            --v[i];
            --v[i+1];
        }
        else if (v[i] == 2) v[i] -= 2;
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
}
