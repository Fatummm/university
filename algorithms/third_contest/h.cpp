#include <iostream>
#include <vector>

struct Node {
    std::vector<int> children;
    int distance = 0;
    Node() = default;
};

void DFS(std::vector<std::vector<int>>& al, std::vector<int>& d, int u) {
    for (int i = 0; i != al[u].size(); ++i) {
        d[al[u][i]] = d[u] + 1;
        DFS(al, d, al[u][i]);
    }
}

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> al(n);
    int root = 0;
    for (int i = 0; i != n; ++i) {
        int x; std::cin >> x;
        if (x == -1) root = i;
        else al[x].push_back(i);
    }
    std::vector<int> distances(n);
    distances[root] = 1;
    DFS(al, distances, root);
    int mx = 0;
    for (int i = 0; i != n; ++i) {
        mx = std::max(mx, distances[i]);
    }
    std::cout << mx;
}