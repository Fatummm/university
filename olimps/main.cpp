#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <stdio.h>
using namespace std;

#define ll long long


template <typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    for (size_t i = 0; i != v.size(); ++i) {
        if (i != 0) out << ' ';
        out << v[i];
    }
    return out;
}

template <typename T>
istream& operator >> (istream& in, const vector<T>& v) {
    for (size_t i = 0; i != v.size(); ++i) {
        in >> v[i];
    }
    return in;
}


bool check(vector<pair<ll, ll>>& v, long double t) {
    long double right = -1e9 - 1, left = 1e9 + 1;
    bool boom = false;
    for (size_t i = 0; i != v.size(); ++i) {
        if (v[i].second > 0) right = max(right, v[i].first + v[i].second * t);
        if (v[i].second < 0 && v[i].first + v[i].second * t < right) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);  
    ll n; cin >> n;
    vector<pair<ll, ll>> v(n);
    bool right = false, left = false;
    long double r = 1000;
    for (ll i = 0; i != n; ++i) {
        cin >> v[i].first >> v[i].second;
        if (v[i].second > 0) right = true;
        if (v[i].second < 0 && right == true) left = true;
        r = max(r, (long double)(1'000'000'0000 / abs(v[i].second)));
    }
    if (!(right == true && left == true)) {
        cout << "-1\n";
        return 0;
    }
    long double mid = 0, l = 0, eps = 0.000'000'000'1f, ans = 0;
    while (r - l > eps) {
        mid = (r - l) / 2 + l;
        if (check(v, mid)) {
            r = mid;
            ans = mid;
        }
        else {
            l = mid;
        }
    }
    ans = (r - l) / 2 + l;
    cout << setprecision(10) << r << '\n';
}