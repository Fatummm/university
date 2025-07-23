#include <iostream>
#include <vector>

void solve() {
    int n; std::cin >> n;
    std::vector<int> v(n);
    std::vector<int> p_min;
    int cur_min = 0;
    for(int i = 0; i != n; ++i) {
        std::cin >> v[i];
    }
    if (n == 2) std::cout << v[0] + std::min(v[0], v[1]);
    else {
        if (v[0] >= v[1]) std::cout << v[0] + v[1];
        else std::cout << v[0] + v[0];
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t; std::cin >> t;
    for (int i = 0; i != t; ++i) {
        solve();
    }
}