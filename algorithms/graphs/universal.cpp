#include <iostream>
#include <deque>
#include <list>
#include <cstdint>
#include <limits>



class Graph {
protected:
    uint64_t edges_number;
    std::deque<std::deque<int64_t>> adjacency_list;
public:
    Graph():
    edges_number(static_cast<uint64_t>(0)) {}

    Graph(uint64_t n): 
    edges_number(static_cast<uint64_t>(0)) {
        adjacency_list.resize(n);
    }

    uint64_t GetEdgesNumber() const {
        return edges_number;
    }

    uint64_t GetNodesNumber() {
        return adjacency_list.size();
    }

    uint64_t GetNodesNumber() const {
        return adjacency_list.size();
    }


    void AddEdge(int64_t u, int64_t v) {
        if (static_cast<uint64_t>(u) >= adjacency_list.size() || static_cast<uint64_t>(v) >= adjacency_list.size()) 
        adjacency_list.resize(static_cast<uint64_t>(std::max(u, v) + 1));
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
        ++edges_number;
    }

    template <typename Container>
    static Graph make_graph(Container& c) {
        Graph tmp;
        for (auto& elem: c) {
            tmp.AddEdge(elem.first, elem.second);
        }
        return tmp;
    }
    
    std::deque<int64_t> GetNeighbours(int64_t node) {
        return adjacency_list[node];
    }

    const std::deque<int64_t> GetNeighbours(int64_t node) const {
        return adjacency_list[node];
    }
};

class DirectedGraph: public Graph {
protected:

public:
    DirectedGraph(): Graph() {}
    DirectedGraph(int64_t n): Graph(n) {}

    void AddEdge(int64_t u, int64_t v) {
        if (static_cast<uint64_t>(u) >= adjacency_list.size() || static_cast<uint64_t>(v) >= adjacency_list.size()) 
        adjacency_list.resize(static_cast<uint64_t>(std::max(u, v) + 1));
        adjacency_list[u].push_back(v);
        ++edges_number;
    }

    template <typename Iter>
    static DirectedGraph make_graph(Iter begin, Iter end) {
        DirectedGraph tmp;
        while (begin != end) {
            tmp.AddEdge(begin->first, begin->second);
            ++begin;
        }
        return tmp;
    }
};

class WeightedGraph: public Graph {
protected:
    std::deque<std::deque<int64_t>> adjacency_matrix;
public:
    WeightedGraph(): Graph() {}
    WeightedGraph(int64_t n): Graph(n) {
        adjacency_matrix.resize(n);
        for (int64_t i = 0; i != n; ++i) {
            adjacency_matrix[i].resize(n, INT64_MAX);
        }
    }

    void AddEdge(int64_t u, int64_t v, int64_t w) {
        if (static_cast<uint64_t>(u) >= adjacency_list.size() || static_cast<uint64_t>(v) >= adjacency_list.size()) {
            uint64_t sz = static_cast<uint64_t>(std::max(u, v) + 1);
            adjacency_list.resize(sz);
            adjacency_matrix.resize(sz); for (uint64_t i = 0; i != sz; ++i) adjacency_matrix[i].resize(sz);
        }
        
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
        
        adjacency_matrix[u][v] = w;
        adjacency_matrix[v][u] = w;
        ++edges_number;
    }
    struct Edge {
        int64_t from;
        int64_t to;
        int64_t weight;        
    };

    template <typename Container>
    static WeightedGraph make_graph(Container& c) {
        WeightedGraph tmp;
        for (Edge& elem: c) {
            tmp.AddEdge(elem.from, elem.to, elem.weight);
        }
        return tmp;
    }

    int64_t GetWeight(int64_t u, int64_t v) const {
        return adjacency_matrix[u][v];
    }
};

class WeightedDirectedGraph: public WeightedGraph {
private:

public:
    WeightedDirectedGraph() {}
    WeightedDirectedGraph(int64_t n): WeightedGraph(n) {}

    void AddEdge(int64_t u, int64_t v, int64_t w) {
        if (static_cast<uint64_t>(u) >= adjacency_list.size() || static_cast<uint64_t>(v) >= adjacency_list.size()) {
            uint64_t sz = static_cast<uint64_t>(std::max(u, v) + 1);
            adjacency_list.resize(sz);
            adjacency_matrix.resize(sz); for (uint64_t i = 0; i != sz; ++i) adjacency_matrix[i].resize(sz);
        }
        
        adjacency_list[u].push_back(v);
        adjacency_matrix[u][v] = w;
        ++edges_number;
    }

    template <typename Container>
    static WeightedDirectedGraph make_graph(Container& c) {
        WeightedDirectedGraph tmp;
        for (auto& elem: c) {
            tmp.AddEdge(elem.from, elem.to, elem.weight);
        }
        return tmp;
    }
};

template <typename Container, typename output = std::ostream>
void print(const Container& c, output& out = std::cout) {
    for (size_t i = 0; i != c.size(); ++i) {
        if (i != 0) out << ' ';
        out << c[i];
    }
}

int main() {
    std::deque<std::pair<int, int>> dq = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {2, 4}, {4, 5}};
    std::deque<WeightedGraph::Edge> dq_new = {{0, 1, 2}, {0, 2, 3}, {1, 2, 2}, {2, 3, 4}, {2, 4, 7}, {4, 5, 1}};
    //DirectedGraph g = DirectedGraph::make_graph(dq.begin(), dq.end());
    //Graph g = Graph::make_graph(dq.begin(), dq.end());
    //WeightedGraph g = WeightedGraph::make_graph(dq_new);
    WeightedDirectedGraph g = WeightedDirectedGraph::make_graph(dq_new);
    print(g.GetNeighbours(2));
    std::cout << '\n' << g.GetWeight(2, 3);
    std::cout << "\nSuccess!\n";
}