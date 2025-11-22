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

//
class DSU {
public:
DSU(int n) : _size(n + 1, 1), _parent(n + 1, -1) {}

bool IsSimilar(int u, int v) {
return GetRoot(u) == GetRoot(v);
}

int getSize(int v) {
return _size[GetRoot(v)];
}

void Unite(int u, int v) {
u = GetRoot(u);
v = GetRoot(v);
if (u == v) {
return;
}
if (_size[u] > _size[v]) {
std::swap(u, v);
}
_parent[u] = v;
_size[v] += _size[u];
}

private:
vector<int> _size;
vector<int> _parent;

int GetRoot(int v) {
if (_parent[v] == -1) {
if (_parent[v] == v) {
    cout << v << '\n';
}
return v;
}
int root = GetRoot(_parent[v]);
_parent[v] = root;
return root;
}
};
//
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
    vector<int> to_root;
    int current = x;
    while (dsu[current].value != current) {
        to_root.push_back(current);
        current = dsu[current].value;
    }
    for (int i = 0; i != to_root.size(); ++i) {
        dsu[to_root[i]].value = current;
    }
    return current;
}

void just_union(int x, int y) {
    if (dsu[find(x)].value != dsu[find(y)].value) {
        dsu[find(x)].value = y;
        dsu[y].rank += dsu[find(x)].rank;
    }
}

bool check(int x, int y, int z) {
    if (dsu[find(x)].value != dsu[find(y)].value) {
        return z <= dsu[find(x)].rank + dsu[find(y)].rank;
    }
    return dsu[find(x)].rank;
}

bool check(int x, int y, int z, DSU& dsu) {
  if (dsu.IsSimilar(x, y)) {
    return dsu.getSize(y) >= z;
  }
  return dsu.getSize(x) + dsu.getSize(y) >= z;
}

void solve() {
    int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  rep(i, m) {
    cin >> edges[i].first >> edges[i].second;
  }
  int q;
  cin >> q;
  vector<int> x(q), y(q), z(q);
  rep(i, q) {
    cin >> x[i] >> y[i] >> z[i];
  }

  vector<int> l(q, 0), r(q, m - 1), ans(q, -1);

  while (true) {
    vector<std::vector<int>> events(m);
    DSU dsu(n);
    int cnt = 0;
    rep(i, q) {
      if (l[i] <= r[i]) {
        int mid = (l[i] + r[i]) / 2;
        events[mid].push_back(i);
        ++cnt;
      }
    }
    if (cnt == 0) {
      break;
    }
    rep(i, m) {
      dsu.Unite(edges[i].first, edges[i].second);
      for (int query : events[i]) {
        if (check(x[query], y[query], z[query], dsu)) {
          ans[query] = i;
          r[query] = i - 1;
        } else {
          l[query] = i + 1;
        }
      }
    }
  }
  for (int answer : ans) {
    cout << answer + 1 << '\n';
  }
}

signed main() {
    solve();
}
