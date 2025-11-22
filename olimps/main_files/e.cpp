#include <bits/stdc++.h>
#define ll long long
#define int ll
#define rep(i, n) for(int i = 0; i < n; ++i)
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define fi first
#define se second
 
using namespace std;
const int inf = 2e9;
 
// set<int, bool (*)(int, int)> st(cmp);
 
template <typename T>
void print(const pair<T, T>& p) {
  cout << '(' << p.fi << ", " << p.se << ')';
}

template <typename T>
void print(const T& v) {
  for (auto el : v) {
    cout << el << ' ';
  }
  cout << '\n';
}
 
void MakeFast() {
  std::ios::sync_with_stdio(NULL);
  std::cin.tie(0);
  std::cout.tie(0);
}

class DSU {
public:
  DSU(int n): data(n + 1) {
    for (size_t i = 0; i != n + 1; ++i) {
      data[i] = i;
    }
  }

  bool IsSimilar(int x, int y) {
    return GetRoot(x) == GetRoot(y);
  }    

  void Unite(int x, int y) {
    if (GetRoot(x) == GetRoot(y)) return;
    if (x > y) swap(x, y);
    data[GetRoot(y)] = GetRoot(x);
  }

  int GetRoot(int x) {
    if (data[x] == x) return x;
    else return data[x] = GetRoot(data[x]);
  }
private:
  vector<int> data;
};

DSU d(1e5);

void dfs(vector<vector<int>>& g, vector<bool>& used, vector<int>& parent, int current) {
  used[current] = true;
  
}

void Solve() {
  int n, k; cin >> n >> k;
  vector<vector<int>> g(n);
  rep(i, k) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> parent(n, -1);
  vector<bool> used;
}

signed main() {
  MakeFast();
  int t = 1;
  //cin >> t;
  while (t--) {
    Solve();
  }
}