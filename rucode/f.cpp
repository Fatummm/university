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
#include <iomanip>

#define int int64_t
#define rep(i, n) for (int i = 0; i != n; ++ i)
#define MOD (1'000'000'000+7)
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int bin_pow(int x, int y) {
    if (y <= 0) return 1;
    if (y % 2 == 0) return bin_pow(x*x % MOD, y/2) % MOD;
    return x * bin_pow(x*x % MOD, y/2) % MOD;
}

void iostreamUntie() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    int n = 6; cin >> n;
    vector<int> vowels(n+1, 0);
    vector<int> consonants(n+1, 0);
    vector<int> specials(n+1, 0);
    vector<int> j(n+1, 0);
    consonants[1] = 20;
    j[1] = 1;
    vowels[1] = 10;
    for (int i = 2; i <= n; ++i) {
        consonants[i] = (vowels[i-1] * 20) % MOD;
        vowels[i] = (specials[i-1] * 10 % MOD) + (consonants[i-1] * 10 % MOD) + (j[i-1] * 10 % MOD);
        specials[i] = (consonants[i-1] * 2) % MOD;
        j[i] = vowels[i-1];
    }
    cout << (consonants[n] + vowels[n] + specials[n] + j[n]) % MOD << '\n';
}

signed main() {
    int t = 1;
    //cin >> t;
    while (t--) solve();
}