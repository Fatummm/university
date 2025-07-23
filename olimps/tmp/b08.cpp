#include <iostream>
#include <vector>
#include <algorithm>


#define ll long long

struct Order {
    ll start;
    ll end;
};

bool operator < (const Order& lhs, const Order& rhs) {
    if (lhs.end == rhs.end) return lhs.start < rhs.start;
    return lhs.end < rhs.end;
}

int main() {
    ll n; std::cin >> n;
    std::vector<Order> v(n);
    for (ll i = 0; i != n; ++i) {
        std::cin >> v[i].start >> v[i].end;
    }
    std::sort(v.begin(), v.end());
    ll orders = 0;
    ll last_end = -1;
    for (ll i = 0; i != n; ++i) {
        if (v[i].start > last_end) {
            ++orders;
            last_end = v[i].end;
        }
    }
    std::cout << orders << '\n';
}