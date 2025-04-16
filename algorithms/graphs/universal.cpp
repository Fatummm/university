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

    const uint64_t GetNodesNumber() const {
        return adjacency_list.size();
    }


    void AddEdge(int64_t u, int64_t v) {
        if (static_cast<uint64_t>(u) >= adjacency_list.size() || static_cast<uint64_t>(v) >= adjacency_list.size()) 
        adjacency_list.resize(static_cast<uint64_t>(std::max(u, v) + 1));
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
        ++edges_number;
    }

    template <typename Iter>
    static Graph make_graph(Iter begin, Iter end) {
        Graph tmp;
        while (begin != end) {
            tmp.AddEdge(begin->first, begin->second);
            ++begin;
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
private:

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

    void AddEdge(int64_t u, int64_t v, double w) {
        if (static_cast<uint64_t>(u) >= adjacency_list.size() || static_cast<uint64_t>(v) >= adjacency_list.size()) 
        adjacency_list.resize(static_cast<uint64_t>(std::max(u, v) + 1));
        adjacency_list[u].push_back(v);
        adjacency_matrix[u][v] = w;
        adjacency_matrix[v][u] = w;
        ++edges_number;
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
    DirectedGraph g = DirectedGraph::make_graph(dq.begin(), dq.end());
    //Graph g = Graph::make_graph(dq.begin(), dq.end());
    print(g.GetNeighbours(2));
    std::cout << '\n' << g.GetEdgesNumber();
    std::cout << "\nSuccess!\n";
}