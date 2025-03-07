#include <iostream>
#include <vector>

struct Item {
    int destination;
    int size;
    Item(int s): size(s), destination(-1) {}
};

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<Item> v;
    int mx = 0;
    for (int i = 0; i != n; ++i) {
        int x; std::cin >> x;
        mx = std::max(mx, x);
        v.push_back(Item(x));
    }
    std::vector<int> ans;
    for (int i = 0; i != m; ++i) {
        int d, s; std::cin >> d >> s;
        --d; --s;
        int destination = d, source = s;
        while (v[destination].destination != -1) {
            destination = v[destination].destination;
        }
        while (v[source].destination != -1) {
            int tmp = source;
            source = v[source].destination;
            v[tmp].destination = destination;
        }
        if (destination != source || (destination == -1 && source == -1)) {
            v[source].destination = destination;
            v[destination].size += v[source].size;
            v[source].size = 0;
            mx = std::max(mx, v[destination].size);
        }
        ans.push_back(mx);
    }
    // for (int i = 0; i != n; ++i) {
    //     std::cout << v[i].size << ' ';
    // }
    for (int i = 0; i != m; ++i) {
        std::cout << ans.at(i) << '\n';
    }
}