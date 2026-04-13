#include <bits/stdc++.h>
#define ll long long
#define int ll
#define rep(i, n) for(int i = 0; i < n; ++i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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
  int n, s, x; cin >> n >> s >> x;
  int sm = 0;
  rep(i, n) {
    int tmp; cin >> tmp;
    sm += tmp;
  }
  if (s >= sm && (s - sm) % x == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

signed main() {
  MakeFast();
  int t = 1;
  cin >> t;
  while (t--) {
    Solve();
  }
}

