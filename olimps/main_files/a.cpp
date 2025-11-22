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

void fill(vector<char>& v) {
  for (int i = 1; i != v.size(); ++i) {
    if (v[i-1] == 'u' && v[i] != 'u') {
      v[i-1] = (v[i] == 'l' ? 'r' : 'l');
    } else if (v[i] == 'u' && v[i-1] != 'u') {
      v[i] = (v[i-1] == 'l' ? 'r' : 'l'); 
    }
  }
}

void fill_reversed(vector<char>& v) {
  for(int i = v.size() - 1; i != 0; --i) {
    if (v[i-1] == 'u' && v[i] != 'u') {
      v[i-1] = (v[i] == 'l' ? 'r' : 'l');
    } else if (v[i] == 'u' && v[i-1] != 'u') {
      v[i] = (v[i-1] == 'l' ? 'r' : 'l'); 
    }
  }
}

vector<int> restore(const vector<char>& v) {
  vector<int> ans(v.size(), 0);
  int r = count(v.begin(), v.end(), 'r');
  ans[0] = r + (v[0] == 'l');
  for(int i = 1; i != v.size(); ++i) {
    if (v[i] != v[i-1]) {
      ans[i] = ans[i-1];
    } else if (v[i] == 'r') {
      ans[i] = ans[i-1] - 1;
    } else {
      ans[i] = ans[i-1] + 1;
    }
  }
  return ans;
}

template <typename Container>
int ask(Container& c) {
  cout << "? " << c.size() << ' ';
  print(c);
  cout.flush();
  int x; cin >> x;
  return x;
}

template <typename Container>
int ask(int x, Container& c) {
  cout << "? " << c.size() + 1 << ' ' << x << ' ';
  print(c);
  cout.flush();
  int val; cin >> val;
  return val;
}

template <typename Container>
void answer(Container& c) {
  cout << "! ";
  print(c);
  cout.flush();
}

int res = 0;

void dfs(vector<vector<int>>& adj_l, vector<bool>& used, vector<int>& costs, int current, int& cur_sm) {
  used[current] = true;
  for(auto node: adj_l[current]) {
    if (!used[node]) {
      cur_sm += costs[node];
      res = max(res, cur_sm);
      dfs(adj_l, used, costs, node, cur_sm);
      cur_sm -= costs[node];
    }
  }
  used[current] = false;
}

void Solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n, vector<int>()); // adjacency list
  vector<int> cost(n);
  rep(i, n) cin >> cost[i];
  res = cost[0];
  rep(i, m) {
    int u, v; cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int cur_sm = cost[0];
  vector<bool> used(n, false);
  dfs(g, used, cost, 0, cur_sm);
  cout << res << '\n';
}

signed main() {
  MakeFast();
  int t = 1;
  //cin >> t;
  while (t--) {
    Solve();
  }
}