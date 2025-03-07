// Depth-first-search
#include <iostream>
#include <map>
#include <list>
#include <vector>

void dfs(std::map<int, std::vector<int>>& al, std::vector<bool>& visited, int u) {
    std::cout << u << ' ';
    visited[u] = true;
    for (size_t i = 0; i != al[u].size(); ++i) {
        if (!visited[al[u][i]]) dfs(al, visited, al[u][i]);
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
    for (size_t i = 0; i != 16; ++i) {
        if (!visited[i]) {
            count++;
            std::cout << "\nComponenta svyaznosti nomer " << count << ": ";
            dfs(adjacency_list, visited, i);
        }
    }
}