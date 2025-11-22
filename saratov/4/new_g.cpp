#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <deque>

using namespace std;
#define int int64_t
#define rep(i, k) for (int i = 0; i != k; ++i)
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vpi = vector<pair<int, int>>;

struct DSU {
public:
    DSU(int n): rank(n + 1, 1), parent(n + 1, -1) {}
    int find(int x) {
        if (parent[x] == -1) return x;
        int root = find(parent[x]);
        parent[x] = root;
        return root;
    }
    void unite(int x, int y) {
        if (find(x) == find(y)) return;
        int root1 = find(x),
        root2 = find(y);
        if (rank[root1] >= rank[root2]) {
            parent[root2] = root1;
            rank[root1] += rank[root2]; 
        } else {
            parent[root1] = root2;
            rank[root2] += rank[root1];
        }
    }

    int get_ranks(int x, int y) {
        return (find(x) != find(y) ? rank[find(x)] + rank[find(y)] : rank[find(x)]);
    }
private:
    vi rank;
    vi parent;
};

struct Node {
    int value;
    int rank;
};

vector<Node> dsu;

void dsu_init() {
    for (int i = 0; i != dsu.size(); ++i) {
        dsu[i].value = i;
        dsu[i].rank = 1;
    }
}

int find(int x) {
    if (dsu[x].value == x) {
        return x;
    }
    int root = find(dsu[x].value);
    dsu[x].value = root;
    return root;
}

void just_union(int x, int y) {
    if (find(x) != find(y)) {
        dsu[find(x)].value = y;
        dsu[y].rank += dsu[find(x)].rank;
    }
}

bool check(int x, int y, int z) {
    if (dsu[find(x)].value != dsu[find(y)].value) {
        return z <= dsu[find(x)].rank + dsu[find(y)].rank;
    }
    return dsu[find(y)].rank >= z;
}

bool check(int x, int y, int z, DSU& dsu) {
    return dsu.get_ranks(x, y) >= z;
}

void solve() {
    int n, m; cin >> n >> m;
    vpi edges(m);
    rep(i, m) {
        cin >> edges[i].first >> edges[i].second;
    }
    int q; cin >> q;
    vi l(q, 0), r(q, m - 1), x(q), y(q), z(q);
    vi ans(q);
    rep(i, q) {
        cin >> x[i] >> y[i] >> z[i];
    }
    while (true) {
        DSU dsu(n);
        vvi events(m, vi(0));
        bool changed = false;
        rep(i, q) {
            if (l[i] <= r[i]) {
                int mid = (r[i] + l[i]) / 2;
                events[mid].push_back(i);
                changed = true;
            }
        }
        if (!changed) break;
        rep(i, m) {
            dsu.unite(edges[i].first, edges[i].second);
            for (auto elem : events[i]) {
                if (check(x[elem], y[elem], z[elem], dsu)) {
                    ans[elem] = i;
                    r[elem] = i - 1;
                }
                else l[elem] = i + 1;
            }
        }
    }
    rep(i, ans.size()) {
        cout << ans[i] + 1 << '\n';
    }
}

signed main() {
    solve();
}
