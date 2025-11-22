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

vector<pair<int, int>> get_neighbours(vector<vector<int>>& mp, int x, int y) {
  vector<pair<int, int>> v;
  if (x != 0) v.push_back({x - 1, y});
  if (x != mp.size() - 1) v.push_back({x + 1, y});
  if (y != 0) v.push_back({x , y - 1});
  if (y != mp[x].size() - 1) v.push_back({x, y + 1});
  return v;
}

bool all_susha(vector<vector<int>>& mp, int x, int y) {
  auto v = get_neighbours(mp, x, y);
  for (auto [nx, ny]: v) {
    if (mp[nx][ny] == 0) return false;
  }
  return true;
}

void get_flooded(vector<vector<int>>& mp, const vector<vector<int>>& fact_heights, int x, int y) {
  auto neigh = get_neighbours(mp, x, y);
  for (auto [nx, ny] : neigh) {
    if (!all_susha(mp, nx, ny) && mp[nx][ny] == inf) {
      mp[nx][ny] = fact_heights[nx][ny];
      get_flooded(mp, fact_heights, nx, ny);
      continue;
    }

    if (mp[nx][ny] != 0 && mp[x][y] < mp[nx][ny]) {
      mp[nx][ny] = max(mp[x][y], fact_heights[nx][ny]);
      get_flooded(mp, fact_heights, nx, ny);
    }
  }
}

void Solve() {
  int n, m; cin >> n >> m;

  vector<vector<int>> heights(n, vector<int>(m, 0));
  vector<vector<int>> flood(n, vector<int>(m, inf));
  
  rep(i, n) {
    rep(j, m) {
      cin >> heights[i][j];
      if (heights[i][j] == 0 || i == 0 || j == 0 || i == n - 1 || j == m - 1) {
        flood[i][j] = heights[i][j];
    }
    }
  }
  rep(i, n) {
    rep(j, m) {
      if (flood[i][j] == heights[i][j]) {
        get_flooded(flood, heights, i, j);
      }
    }
  }
  rep(i, n) {
    print(flood[i]);
  }
}

signed main() {
  MakeFast();
  int t = 1;
  //cin >> t;
  while (t--) {
    Solve();
  }
}