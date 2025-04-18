#include <vector>
#include <iostream>
#include "universal.hpp"

#define MAXN 10000
#define INF 100000

int distance[MAXN][MAXN];

void FloydWarshall(fatum::WeightedGraph& g) {
    for (int k = 0; k != g.GetNodesNumber(); ++k) {
        for (int from = 0; from != g.GetNodesNumber(); ++from) {
            for (int to = 0; to != g.GetNodesNumber(); ++to) {
                distance[from][to] = std::min(distance[from][to], distance[from][k] + distance[k][to]);
            }
        }
    }
}

int main() {
    std::vector<fatum::WeightedGraph::Edge> weighted_edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 5, 4}, {2, 8, 2}, {3, 4, 9}, {3, 5, 14},
        {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}
    };
    fatum::WeightedGraph g = fatum::WeightedGraph::make_graph(weighted_edges);

    for (int i = 0; i != g.GetNodesNumber(); ++i) {
        for (int j = 0; j != g.GetNodesNumber(); ++j) {
            distance[i][j] = g.GetWeight(i, j);
            
        }
        distance[i][i] = 0;
    }

    FloydWarshall(g);
    std::cout << "The shortest paths from 1:\n";
    for (int i = 0; i != g.GetNodesNumber(); ++i) {
        if (i != 0) std::cout << '\n';
        std::cout << "to " << i << " is " << distance[1][i];
    }
}