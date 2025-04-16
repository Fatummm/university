#include <iostream>
#include <vector>
#include <set>

struct Vbox;
struct Wbox;

struct Vbox {
    int volume;
    int index;
    Vbox(int v, int ind): volume(v), index(ind) {}
};
bool operator < (const Vbox& first, const Vbox& second) {
    return (first.volume == second.volume) ? second.index < first.index : first.volume < second.volume;
}

struct Wbox {
    int weight;
    int index;
    Wbox(int w, int ind): weight(w), index(ind) {}

    
};
bool operator < (const Wbox& first, const Wbox& second) {
    return (first.weight == second.weight) ? second.index < first.index : first.weight < second.weight;
}



class Stock {
private:
    std::set<Vbox> volumes;
    std::set<Wbox> weights;
    std::vector<std::pair<std::set<Vbox>::iterator, std::set<Wbox>::iterator>> iters;
public:
    void Add(int w, int v) {
        volumes.insert(Vbox(v, iters.size()));
        weights.insert(Wbox(w, iters.size()));
        iters.push_back({volumes.find(Vbox(v, iters.size())), weights.find(Wbox(w, iters.size()))});
    }

    int GetByW(int min_w) {
        int index = (weights.lower_bound(Wbox(min_w, iters.size())) != weights.end()) ? weights.lower_bound(Wbox(min_w, iters.size()))->index : -1;
        if (index == -1) return index;
        volumes.erase(iters[index].first);
        weights.erase(iters[index].second);
        return index;
    }

    int GetByV(int min_v) {
        int index = (volumes.lower_bound(Vbox(min_v, iters.size())) != volumes.end()) ? volumes.lower_bound(Vbox(min_v, iters.size()))->index : -1;
        if (index == -1) return -1;
        volumes.erase(iters[index].first);
        weights.erase(iters[index].second);
        return index;
    }
};


int main() {
    Stock s;
    s.Add(3, 2);
    s.Add(3, 2);
    s.Add(3, 2);
    s.Add(3, 2);
    s.Add(3, 1);
    std::cout << s.GetByV(2) << '\n';
    std::cout << "Success\n";
}