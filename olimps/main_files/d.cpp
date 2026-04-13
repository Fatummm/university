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
  int n; cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) {
    cin >> a[i];
  }
  rep(i, n) {
    cin >> b[i];
  }
  vector<int> pref_b(n + 1, 0);
  rep(i, n) {
    pref_b[i + 1] = pref_b[i] + b[i];
  }
  // pref[i] - сколько мечей нужно для прохождения i уровней включительно
  sort(all(a));
  int mx = 0;
  //print(pref_b);
  rep(i, n) {
    int swords = n - i;
    //cout << "swords: " << swords << '\n';
    auto it = lower_bound(all(pref_b), swords);
    if (it != pref_b.end() && it != pref_b.begin() && *it > swords) --it;
    int levels = it - pref_b.begin();
    //cout << "difficulty: " << a[i] << '\n' << "levels: " << levels << '\n';
    mx = max(mx, a[i] * levels);
    while (i != n - 1 && a[i] == a[i+1]) ++i;
  }
  cout << mx << '\n';
}

signed main() {
  MakeFast();
  int t = 1;
  cin >> t;
  while (t--) {
    Solve();
  }
}

