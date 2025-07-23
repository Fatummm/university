#include <iostream>
#include <vector>

#include <cstdint>
#include <limits>

#define int int64_t

struct Node {
    int time = std::numeric_limits<int>::max();
    int time_in_waiting = std::numeric_limits<int>::max();
};

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> adjl(n);
    for (int i = 0; i != m; ++i) {
        int u, v; std::cin >> u >> v;
        --u; --v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }
    std::vector<Node> ans(n);
    ans[0].time = 0;
    ans[0].time_in_waiting = 0;
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            if (ans[j].time != std::numeric_limits<int>::max()) {
                for (int k = 0; k != adjl[j].size(); ++k) {
                    int current = adjl[j][(ans[j].time + k) % adjl[j].size()];
                    if (ans[current].time > ans[j].time + k + 1 || 
                        (ans[current].time == ans[j].time + k + 1 && 
                            ans[current].time_in_waiting > ans[j].time_in_waiting + k)) {
                        ans[current].time = ans[j].time + k + 1;
                        ans[current].time_in_waiting = ans[j].time_in_waiting + k;
                    }
                }
            }
        }
    }
    std::cout << ans[1].time_in_waiting << '\n';
    std::cout << ans.back().time << ' ' << ans.back().time_in_waiting << '\n';
}

signed main() {
    // int t; std::cin >> t;
    // for (int i = 0; i != t; ++i) {
    //     solve();
    // }
    solve();
}