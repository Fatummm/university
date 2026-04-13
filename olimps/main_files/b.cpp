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

void reverse(vector<int>& v, int l, int r) {
  while (l < r) {
    swap(v[l++], v[r--]);
  }
}

void Solve() {
  int n; cin >> n;
  vector<int> p(n);
  rep(i, n) {
    cin >> p[i];
  }
  rep(i, n) {
    if (p[i] == n - i) skip;
    for (int j = i + 1; j != n; ++j) {
      if (p[j] == n - i) {
        reverse(p, i, j);
        break;
      }
    }
    break;
  }
  print(p);
}

signed main() {
  MakeFast();
  int t = 1;
  cin >> t;
  while (t--) {
    Solve();
  }
}

