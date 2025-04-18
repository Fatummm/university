// Breadth-first-search
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include "universal.hpp"

void bfs(fatum::Graph& g, std::vector<bool>& visited, int64_t start) {
    std::queue<int> q; q.push(start);
    while (!q.empty()) {
        int current = q.front(); q.pop();
        visited[current] = true;
        if (current != start) std::cout << ' ';
        std::cout << current;
        for (auto& elem: g.GetNeighbours(current)) {
            if (!visited[elem]) q.push(elem);
            visited[elem] = true;
        }
    }
}

int main() {
    std::vector<std::pair<int64_t, int64_t>> edges = {
        {0, 1}, {0, 7}, {1, 2}, {1, 7}, {2, 3}, {2, 5}, {2, 8}, {3, 4}, {3, 5},
        {4, 5}, {5, 6}, {6, 7}, {6, 8}, {7, 8}
    };
    std::vector<fatum::WeightedGraph::Edge> weighted_edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 5, 4}, {2, 8, 2}, {3, 4, 9}, {3, 5, 14},
        {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}
    };
    fatum::Graph g = fatum::Graph::make_graph(edges);
    std::vector<bool> visited(g.GetNodesNumber(), false);
    bfs(g, visited, 0);
}