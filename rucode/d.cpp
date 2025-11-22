#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include <random>
#include <chrono>

#define int int64_t
#define rep(i, n) for (int i = 0; i != n; ++ i)

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int bin_pow(int x, int y) {
    if (y <= 0) return 1;
    if (y % 2 == 0) return bin_pow(x*x, y/2);
    return x * bin_pow(x*x, y/2);
}

void iostreamUntie() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}


void solve() {
    int x, y, r; cin >> x >> y >> r;
    int colors = 0;
    if (x != 0 && y != 0) {
        colors = 1;
        if (abs(x) == r) colors += 1; // black
        else if (abs(x) < r) colors += 2; // black and other

        if (abs(x) > r && abs(y) == r) colors += 1; // black
        else if (abs(x) > r && abs(y) < r) colors += 2; // black and other
        else if (abs(x) <= r && abs(y) < r) colors += 1; // other, black was added

        if (x * x + y * y < r * r) colors += 1;
    }
    else if (x == 0 && y != 0) {
        colors = 3;
        if (abs(y) < r) colors += 2;
    } else if (x != 0 && y == 0) {
        colors = 3;
        if (abs(x) < r) colors += 2;
    }
    else if (x == 0 && y == 0) {
        colors = 5;
    }
    cout << colors << '\n';
}

signed main() {
    int t = 1;
    //cin >> t;
    while (t--) solve();
}