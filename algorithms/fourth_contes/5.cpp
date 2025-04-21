#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void dfs(std::vector<std::vector<int>>& adjacency_list, std::vector<bool>& used, std::vector<int>& path,
     std::vector<std::vector<int>>& ans) {
    if (path.size() == adjacency_list.size()) {
        ans.emplace_back();
        for (int i = path.size() - 1; i >= 0; --i) {
            ans.back().push_back(path[i]);
        }
        return;
    }
    for (int node = 0; node != adjacency_list.size(); ++node) {
        if (used[node]) continue;

        bool kaif = true;
        for (int j = 0; j != adjacency_list[node].size(); ++j) {
            if (!used[adjacency_list[node][j]]) kaif = false;
        }

        // Мы можем включить вершину в путь
        if (kaif) {
            used[node] = true;
            path.push_back(node);
            dfs(adjacency_list, used, path, ans);
            used[node] = false;
            path.pop_back();
        }
    }
    
}

int main() {
    int n;std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i != n; ++i) {
        int number; std::cin >> number;
        for(int j = 0; j != number; ++j) {
            int tmp; std::cin >> tmp;
            adj[i].push_back(tmp);
        }
    }
    std::vector<std::vector<int>> ans;
    std::vector<bool> visited(n, false);
    std::vector<int> path;
    for (int i = 0; i != n; ++i) {
        if (adj[i].empty()) {
            path.push_back(i);
            visited[i] = true;
            dfs(adj, visited, path, ans);
            visited[i] = false;
            path.pop_back();
        }
    }
    
    if (!ans.empty()) {
        std::cout << ans.size() << '\n';
        for (int i = 0; i != ans.size(); ++i) {
            for (int j = 0; j != ans[i].size(); ++j) {
                if (j != 0) std::cout << ' ';
                std::cout<< ans[i][j];
            }
            std::cout << '\n';
        }
    }
    else {
        std::cout << "Impossible\n";
    }
}