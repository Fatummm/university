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

void iostreamUntie() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

int isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i < static_cast<int>(sqrt(n)) + 1; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
void solve() {
    int n; cin >> n;
    if (isPrime(n)) cout << 1;
    else if (n % 2 == 0) cout << 2;
    else cout << 3;
}

signed main() {
    iostreamUntie();
    int t = 1;
    //cin >> t;
    while (t--) solve();
}