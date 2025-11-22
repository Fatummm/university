#include <iostream>
#include <vector>
#include <cstdint>
#include <string>

#define int int64_t
using namespace std;

void solve() {
    string s = "L";
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i != n; ++i) cin >> v[i];
    int left = 1, right = n - 1;
    while (s.size() != n) {
        if (left == right) s += 'L';
        else if (v[left - 1] > v[left] && v[left - 1] > v[right] && v[left] > v[right]) {s += 'R'; s += 'L';}
        else if (v[left - 1] > v[left] && v[left - 1] > v[right] && v[left] < v[right]) {s += 'L'; s += 'R';}
        else if (v[left - 1] > v[left] && v[left - 1] < v[right]) {s += 'L'; s += 'R';}
        else if (v[left - 1] < v[left] && v[left - 1] > v[right]) {s += 'L'; s += 'R';}
        else if (v[left - 1] < v[left] && v[left - 1] < v[right] && v[left] > v[right]) {s += 'L'; s += 'R';}
        else if (v[left - 1] < v[left] && v[left - 1] < v[right] && v[left] < v[right]) {s += 'R'; s += 'L';}
        ++left; --right;
    }
    cout << s << '\n';
}

signed main() {
    int t; cin >> t;
    for (int i = 0; i != t; ++i) solve();
}
