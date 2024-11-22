#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <stdio.h>
using namespace std;

#define ll long long


// template <typename T>
// ostream& operator << (ostream& out, const vector<T>& v) {
//     for (size_t i = 0; i != v.size(); ++i) {
//         if (i != 0) out << ' ';
//         out << v[i];
//     }
//     return out;
// }

// template <typename T>
// istream& operator >> (istream& in, const vector<T>& v) {
//     for (size_t i = 0; i != v.size(); ++i) {
//         in >> v[i];
//     }
//     return in;
// }
bool check(vector<pair<ll, ll>>& v, long double t) {
    long double mx_right = -1e10 - 1, mn_left = 1e10 + 1;
    for (int i = 0; i != v.size(); ++i) {
        if (v[i].second > 0) {
            mx_right = max(mx_right, v[i].first + v[i].second * t);
        }
        else {
            mn_left = min(mn_left, v[i].first + v[i].second * t);
            if (mx_right >= mn_left && v[i].second < 0) {
                return 1;
            }
        }   
    }
    return 0;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(NULL); cout.tie(NULL);  
    ll n; scanf("%lld", &n);
    cout.precision(20);
    vector<pair<ll, ll>> v(n);
    long double eps = 0.000'000'000'1;
    long double r = 0, l = 0, ans = 0, mid = 0;
    
    for (int i = 0; i != n; ++i) {
        scanf("%lld %lld", &v[i].first, &v[i].second);
        r = max(r, (long double)(1'000'000'0000 / abs(v[i].second)));
    }
    // cout << "r =" <<  r << '\n';
    // cout << check(v, 0.02685546875);
    int last_left_index = -1;
    int first_right_index = -1;
    for (int i = 0; i != n; ++i) {
        if (v[i].second > 0 && first_right_index == -1) first_right_index = i;
        if (v[i].second < 0) last_left_index = i;
    }
    if (last_left_index == -1 || first_right_index == -1 || 
    (first_right_index > last_left_index)) {
        cout << -1;
        return 0;
    }
    //cout << r;
    while (r - l > eps) {
        mid = (r - l) / 2 + l;
        //cout << mid << '\n';
        if (check(v, mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << mid;
    
}