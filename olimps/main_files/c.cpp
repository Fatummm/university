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
  int n, q; cin >> n >> q;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) {
    cin >> a[i];
  }
  rep(i, n) {
    cin >> b[i];
    if (b[i] > a[i]) {
      a[i] = b[i];
    }
  }
  for (int i = n - 1; i != 0; --i) {
    if (a[i-1] < a[i]) {
      a[i-1] = a[i];
    }
  }
  vector<int> pref(n + 1, 0);
  rep(i, n) {
    pref[i + 1] = pref[i] + a[i];
  }
  rep(i, q) {
    int l, r; cin >> l >> r;
    cout << pref[r] - pref[l-1] << ' ';
  } cout << '\n';
}

signed main() {
  MakeFast();
  int t = 1;
  cin >> t;
  while (t--) {
    Solve();
  }
}

