#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <set>

#define ll long long
#define ull unsigned long long

ll build_path(std::vector<std::vector<ll>>& am, std::vector<ll>& p, std::vector<bool>& used,
    ll current_node, ll cost, ll cnt, ll start_and_finish) {
    if (cnt == am[current_node].size() && current_node == start_and_finish) {
        //std::cout << ' ' << current_node << ' ';
        return cost;
    }
    else if (cnt >= am.size()) return INT64_MAX;
    ll mn = INT64_MAX, index = 1;
    for (int i = 0; i != am[current_node].size(); ++i) {
        if (mn > am[current_node][i] && !used[i] && am[current_node][i] != 0) {
            if (cnt + 1 != am.size() && i == start_and_finish) continue;
            mn = am[current_node][i];
            index = i;
        }
    }
    used[index] = true;
    p[index] = current_node;
    return build_path(am, p, used, index, cost + mn, cnt + 1, start_and_finish);
}

int main() {
    ll n; std::cin >> n;
    std::vector<std::vector<ll>> adjacency_matrix(n);
    for (int i = 0; i != n; ++i) adjacency_matrix[i].resize(n, 0);
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            std::cin >> adjacency_matrix[i][j];
        }
    }
    std::vector<bool> visited(n, false);
    std::vector<ll> predecessor(n, -1);
    ll ans = INT64_MAX;
    for (int i = 0; i != n; ++i) {
        ans = std::min(build_path(adjacency_matrix, predecessor, visited, i, 0, 0, i), ans);
        for (int j = 0; j != n; ++j) visited[j] = false;
    }
    int index;
    for (int i = 0; i != n; ++i) {
        if (ans == build_path(adjacency_matrix, predecessor, visited, i, 0, 0, i)) {
            index = i;
            break;
        }
        for (int j = 0; j != n; ++j) visited[j] = false;
    }
    std::vector<ll> path;
    for (int i = 0; i != n; ++i) {
        path.push_back(index);
        index = predecessor[index];
    }
    std::cout << "Path:\n";
    std::cout << path.front() << ' ';
    while (!path.empty()) {
        std::cout << path.back() << ' ';
        path.pop_back();
    }
    std::cout << '\n' << "Cost: " << ans << '\n';
}