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
#include <cstring>

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

void solve() {
    string s; cin >> s;
    if (s.find(':') != std::string::npos) {
        int res = 0;
        res += ((s[0] - '0') * 10 + (s[1] - '0')) * 60 * 60;
        res += ((s[3] - '0') * 10 + (s[4] - '0')) * 60;
        res += ((s[6] - '0') * 10 + (s[7] - '0'));
        cout << res << '\n';
    }
    else {
        int ans = atoi(s.c_str());
        int hours = ans / 60 / 60,
        minutes = ans / 60 % 60,
        seconds = ans % 60;
        if (hours < 10) cout << '0' << hours << ':';
        else cout << hours << ':';
        if (minutes < 10) cout << '0' << minutes << ':';
        else cout << minutes << ':';
        if (seconds < 10) cout << '0' << seconds << '\n';
        else cout << seconds << '\n';
    }
}

signed main() {
    int t = 1;
    //cin >> t;
    while (t--) solve();
}