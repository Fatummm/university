#include <iostream>
#include <vector>
#include <cstdint>

#define ll long long

ll build_path(std::vector<std::vector<ll>>& am, std::vector<bool>& visited, std::vector<ll>& path, ll current, ll start) {
    if (current == start && path.size() == am.size()) {
        ll ans = 0;
        for (int i = 1; i != path.size(); ++i) {
            ans += am[path[i - 1]][path[i]];
        }
        return ans + am[path.back()][path.front()];
    }
    ll mn = INT64_MAX, index = -1;
    for (int i = 0; i != am[current].size(); ++i) {
        if (i == start && path.size() != am.size() - 1) continue;
        if (!visited[i] && am[current][i] < mn && am[current][i] != 0) {
            mn = am[current][i];
            index = i;
        }
    }
    if (index == -1) return INT64_MAX;

    visited[index] = true;
    path.push_back(index);
    return build_path(am, visited, path, index, start);
}


int main() {
    ll n; std::cin >> n;
    std::vector<std::vector<ll>> adjacency_matrix(n);
    for (ll i = 0; i != n; ++i) adjacency_matrix[i].resize(n, 0);
    for (ll i = 0; i != n; ++i) {
        for (ll j = 0; j != n; ++j) {
            std::cin >> adjacency_matrix[i][j];
        }
    }
    std::vector<bool> visited(n, false);
    std::vector<ll> predecessor(n, -1);
    std::vector<ll> path;
    ll ans = INT64_MAX;
    int index = 1;
    for (int i = 0; i != n; ++i) {
        ll res = build_path(adjacency_matrix, visited, path, i, i);
        if (res < ans) {
            index = i;
            ans = res;
        }
        path.clear();
        for (int i = 0; i != n; ++i) visited[i] = false;
    }
    build_path(adjacency_matrix, visited, path, index, index);
    if (ans == INT64_MAX) {
        std::cout << "Lost\n";
        return 0;
    }
    std::cout << "Path:\n" << path.back();
    for (int i = 0; i != path.size(); ++i) {
        std::cout << ' ' << path[i];
    }
    std::cout << '\n' << "Cost: " << ans << '\n';
}
    