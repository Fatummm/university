#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

#define ll long long
#define ld long double

struct Particle {
    ll position;
    ll speed;
};

bool solve(const std::vector<Particle>& v, ld time) {
    long double eps = -0.000'000'000'1;
    long double mx_right = -1e20-1;
    for (ll i = 0; i != v.size(); ++i) {
        if (v[i].speed > 0) {
            if (1e11 / time < v[i].speed) {
                mx_right = 1e11;
            }
            else mx_right = std::max(mx_right, static_cast<ld>(v[i].position) + static_cast<ld>(v[i].speed) * time);
            continue;
        }
        ld pos;
        if (1e11 / time < -v[i].speed) pos = -1e11;
        else pos = static_cast<ld>(v[i].position) + static_cast<ld>(v[i].speed) * time;
        if (pos < mx_right) return true;
    }
    return false;
}

bool check(const std::vector<Particle>& v) { // false if impossible to explode
    if (v.size() == 1) return false;
    double sign = v[0].speed;
    for (int i = 0; i != v.size(); ++i) {
        if (static_cast<double>(v[i].speed) / sign < 0) {
            if (sign > 0) return true;
            sign = 1;
        }
    }
    return false;
}
int main() {
    ll n; std::cin >> n;
    std::cout << std::setprecision(11);
    std::vector<Particle> v(n);
    ll mx;
    for (int i = 0; i != n; ++i) {
        std::cin >> v[i].position >> v[i].speed;
        mx = std::max(mx, v[i].speed);
    }
    if (!check(v)) {
        std::cout << -1 << '\n';
        return 0;
    }
    ld eps = 0.000'000'000'1;
    ld right = 1e13;
    ld left = 0;
    ld mid;
    ld ans;
    while (eps < right - left) {
        mid = (right - left) / 2;
        if (solve(v, left + mid)) {
            ans = left + mid;
            right = left + mid;
        }
        else {
            left = left + mid;
        }
    }
    std::cout << ans << '\n';
    //std::cout << solve(v, 0.0000096123);
}