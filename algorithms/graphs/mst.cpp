// MSP - Minimum Spanning Tree
#include <iostream>
#include <vector>
#include "universal.hpp"
#include <algorithm>
#include <set>

#define MAXN 10000
#define INF 100000

int disjoint_set_union[MAXN];


void makeSet(int x) {
    disjoint_set_union[x] = x;
}

int findSet(int x) {
    int root = x;
    while (disjoint_set_union[root] != root) {
        root = disjoint_set_union[root];
    }
    while (x != root) {
        int tmp = disjoint_set_union[x];
        disjoint_set_union[x] = root;
        x = tmp;
    }
    return root;
}

void unionSet(int a, int b) {
    disjoint_set_union[findSet(a)] = findSet(b);
}

fatum::WeightedGraph Kruskal(fatum::WeightedGraph& g, std::vector<fatum::WeightedGraph::Edge> edges) {
    fatum::WeightedGraph graph;
    // MAKE_SET
    for (int i = 0; i != g.GetNodesNumber(); ++i) {
        makeSet(i);
    }
    std::sort(edges.begin(), edges.end(), 
    [](fatum::WeightedGraph::Edge a, fatum::WeightedGraph::Edge b){return a.weight < b.weight;});
    for (fatum::WeightedGraph::Edge edge: edges) {
        if (findSet(edge.from) != findSet(edge.to)) {
            graph.AddEdge(edge.from, edge.to, edge.weight);
            unionSet(edge.from, edge.to);
        }
    }
    return graph;
}

// fatum::WeightedGraph Prim(fatum::WeightedGraph& g, std::vector<fatum::WeightedGraph::Edge> e, int start = 0) {
//     fatum::WeightedGraph graph;
//     std::vector<int> distance(g.GetNodesNumber(), INF);
//     distance[start] = 0;
//     std::vector<int> predecessor(g.GetNodesNumber(), -1);
//     int u = start;
//     auto comparator = [&](int a, int b){return a < b;};
//     std::set<std::pair<int, int>> edges;
//     for (int elem: g.GetNeighbours(u)) {
//         edges.insert({g.GetWeight(u, elem), elem});
//         predecessor[elem] = u;
//         distance[elem] = g.GetWeight(u, elem);
//     }
//     while (!edges.empty()) {
//         auto tmp = *edges.begin();
//         edges.erase(edges.begin());
//         std::cout << tmp.second;
//         std::cout << "1\n";
//         if (distance[tmp.second] > g.GetWeight(predecessor[tmp.second], tmp.second)) {
//             graph.AddEdge(predecessor[tmp.second], tmp.second, g.GetWeight(predecessor[tmp.second], tmp.second));
//             distance[tmp.second] = g.GetWeight(predecessor[tmp.second], tmp.second);

//             for (int elem: g.GetNeighbours(tmp.second)) {
//                 if (predecessor[elem] == -1) {
//                     edges.insert({g.GetWeight(tmp.second, elem), elem});
//                 }
//             }
//         }
//     }
//     return graph;
// }

int main() {
    std::vector<fatum::WeightedGraph::Edge> weighted_edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 5, 4}, {2, 8, 2}, {3, 4, 9}, {3, 5, 14},
        {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}
    };
    fatum::WeightedGraph g = fatum::WeightedGraph::make_graph(weighted_edges);
    for (int i = 0; i != g.GetNodesNumber(); ++i) {
        disjoint_set_union[i] = i;
    }
    fatum::WeightedGraph graphichek = Kruskal(g, weighted_edges);
    fatum::print_container(graphichek.GetNeighbours(5));
    
}