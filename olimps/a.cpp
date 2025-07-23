#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i != n; ++i) std::cin >> v[i];
    std::vector<int> ans;
    for (int i = 0; i != n && ans.size() == 0; ++i) {
        for(int j = i + 1; j != n && ans.size() == 0; ++j) {
            if (v[i] > v[j]) {
                ans.push_back(v[i]);
                ans.push_back(v[j]);
            }
        }
    }
    if (ans.size() == 2) {
        std::cout << "YES\n" << 2 << '\n';
        std::cout << ans[0] << ' ' << ans[1] << '\n';
    }
    else std::cout << "No\n";
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    std::cin >> t;
    for (int i = 0; i != t; ++i) {
        solve();
    }
}