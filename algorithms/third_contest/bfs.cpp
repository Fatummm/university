// Breadth-first-search
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <queue>

void bfs(std::map<int, std::vector<int>>& al, std::vector<bool>& visited, std::vector<int>& distance, int u) {
    std::queue<int> q;
    q.push(u);
    int d = 0;
    while (!q.empty()) {
        u = q.front();
        visited[u] = true;
        for (auto elem : al[u]) {
            if (!visited[elem]) {
                q.push(elem);
                distance[elem] = distance[u] + 1;
            }
        }
        q.pop();
    }
}

int main() {
    std::map<int, std::vector<int>> adjacency_list;
    adjacency_list.insert({0, {1, 2}});
    adjacency_list.insert({1, {0}});
    adjacency_list.insert({2, {0, 3, 14}});
    adjacency_list.insert({3, {2, 8, 9}});
    adjacency_list.insert({4, {6}});
    adjacency_list.insert({5, {8}});
    adjacency_list.insert({6, {4, 7}});
    adjacency_list.insert({7, {6}});
    adjacency_list.insert({8, {3, 5}});
    adjacency_list.insert({9, {3}});
    adjacency_list.insert({10, {11, 12}});
    adjacency_list.insert({11, {10, 12, 13}});
    adjacency_list.insert({12, {10, 11, 13}});
    adjacency_list.insert({13, {11, 12}});
    adjacency_list.insert({14, {2, 15}});
    adjacency_list.insert({15, {14}});
    std::vector<bool> visited(16, false);
    int count = 0;
    std::vector<int> distance(16, 0);
    bfs(adjacency_list, visited, distance, 0);
    for (int i = 0; i != 16; ++i) {
        std::cout << i << ": " << distance[i] << '\n';
    }
}