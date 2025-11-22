#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include <random>
#include <chrono>
#include <ranges>
#include <cstdlib>
#include <numeric>
#include <iomanip>

#define int int64_t
#define rep(i, n) for (int i = 0; i != n; ++ i)
#define all(v) v.begin(), v.end()

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

int gcd(int n, int m) {
    if (m == 0) return n;
    return gcd(m, n % m);
}

int bin_pow(int x, int y, int m) {
    if (y == 0) return 1 % m;
    if (y % 2 == 0) return bin_pow(x*x % m, y/2, m);
    return (x * bin_pow(x*x % m, y/2, m)) % m;
}

int bin_multiple(int x, int y, int m) {
    if (y == 0) return 0;
    if (y == 1) return x % m;
    if (y % 2 == 1) return (x + bin_multiple((x + x) % m, y/2, m)) % m;
    return bin_multiple((x + x) % m, y/2, m);
}
const int N = 2e5;
const int D = 259;
struct botwa {
    list<int> data;

    int get(int i) {
        auto it = data.begin();
        advance(it, i);
        return *it;
    }

    void add(int i, int val) {
        auto it = data.begin();
        advance(it, i);
        data.insert(it, val);
    }
};

botwa S[N/D + 1]{};

void make_lower(string& s) {
    rep(i, s.size()) {
        if ('A' <= s[i] && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
    }
}

bool is_vowel(char c) {
    return c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i';
}

bool is_consonant(char c) {
    return !is_vowel(c);
}

int check(int a, int b, int c) {
    int res = 0;
    if (a + b == c || b + c == a || a + c == b) return 1;
    if (a + b > c && a + c > b && b + c > a) return 2;
    return 0;
}

void solve() {
    int a[4];
    rep(i, 4) cin >> a[i];
    sort(a, a + 4);
    int flag = 0;
    rep(i, 4) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (i == j || i == k || k == j) continue;
                flag = max(flag, check(a[i], a[j], a[k]));
            }
        }
    }
    if (flag == 0) cout << "IMPOSSIBLE\n";
    else if (flag == 1) cout << "SEGMENT\n";
    else cout << "TRIANGLE\n";
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    iostreamUntie();
    int t = 1;
    //cin >> t;
    while (t--) solve();
}

// g++ tmp.cpp -faddress=sanitize -Wpedantic -Wall -Wextra