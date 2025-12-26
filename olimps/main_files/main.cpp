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
#define skip continue 


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

void Solve() {
  int n, m; cin >> n >> m;
  int score = 0;
  int cur_wal = 0;
  int cur_minute = 0;
  rep(i, n) {
    int minute, wall;
    cin >> minute >> wall;
    int dif = minute - cur_minute;
    if ((dif % 2 == 0 && wall != cur_wall) || (diff % 2 == 1 && wall == cur_wall)) {
      score += dif - 1;
    } else {
      score += dif;
    }
    cur_minute = minute;
  }
  int dif = 
}

signed main() {
  MakeFast();
  int t = 1;
  cin >> t;
  while (t--) {
    Solve();
  }
}
