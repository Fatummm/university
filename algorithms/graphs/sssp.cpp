// Single-Source-Shortest-Path
#include "universal.hpp"
#include <vector>
#include <iostream>
#include <queue>
#include <set>

#define MAXN 10000
#define INF 100000

int distance[MAXN];
int predecessor[MAXN];

void InitSingleSource(fatum::WeightedGraph& g, int64_t start) {
    for (int i = 0; i != g.GetNodesNumber(); ++i) {
        distance[i] = INF;
        predecessor[i] = -1;
        
    }
    distance[start] = 0;
}   

void Relax(fatum::WeightedGraph& g, int64_t from, int64_t to) {
    if (distance[to] > distance[from] + g.GetWeight(from, to)) {
        distance[to] = distance[from] + g.GetWeight(from, to);
        if (distance[to] == 0) std::cout << "\nfrom " << from << " to " << to << '\n';
        predecessor[to] = from;
    }
}

bool BellmanFord(fatum::WeightedGraph& g, int64_t start) {
    InitSingleSource(g, start);
    for (int64_t cnt = 0; cnt != g.GetNodesNumber(); ++cnt) {
        for (int64_t u = 0; u != g.GetNodesNumber(); ++u) {
            for (int64_t v = 0; v != g.GetNodesNumber(); ++ v) {
                Relax(g, u, v);
            }
        }
    }

    for (int64_t u = 0; u != g.GetNodesNumber(); ++u) {
        for (int64_t v = 0; v != g.GetNodesNumber(); ++ v) {
            if (distance[v] > distance[u] + g.GetWeight(u, v)) return false;
        }
    }
    return true;
}

void Dijkstra(fatum::WeightedGraph& g, int64_t start) {
    InitSingleSource(g, start);
    std::set<std::pair<int64_t, int64_t>> q;
    q.insert({0, start});
    while (!q.empty()) {
        int u = q.begin()->second;
        q.erase(q.begin());
        for (int elem: g.GetNeighbours(u)) {
            if (distance[elem] > distance[u] + g.GetWeight(u, elem)) {
                q.erase({distance[elem], elem});
                distance[elem] = distance[u] + g.GetWeight(u, elem);
                q.insert({distance[elem], elem});
            }
        }
    }
    
}

int main() {
    // for (int i = 0; i != MAXN; ++i) {
    //     distance[i] = INF;
    // }
    std::vector<fatum::WeightedGraph::Edge> weighted_edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 5, 4}, {2, 8, 2}, {3, 4, 9}, {3, 5, 14},
        {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}
    };
    fatum::WeightedGraph g = fatum::WeightedGraph::make_graph(weighted_edges);
    
    Dijkstra(g, 0);
    std::cout << "The shortest paths from 0:\n";
    for (int i = 0; i != g.GetNodesNumber(); ++i) {
        if (i != 0) std::cout << '\n';
        std::cout << "to " << i << " is " << distance[i];
    }
    std::cout << '\n' << distance[100];
}