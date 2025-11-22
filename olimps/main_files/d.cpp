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

class SegmentTree {
public:
  explicit SegmentTree(int n): n(n), s(n * 4, 0) {}

  void add(int p, int x) {
    add(0, 0, n, p, x);
  }

  int get(int l, int r) {
    return get(0, 0, n, l, r);
  }

  void set(int p, int x) {
    add(p, x - get(p, p + 1));
  }

private:
  int n;
  vector<int> s;

  void add(int t, int tl, int tr, int p, int x) {
    if (tr - tl == 1) {
      s[t] += x;
      return;
    }
    int tc = tl + (tr - tl) / 2;
    if (p < tc) {
      add(2 * t + 1, tl, tc, p, x);
    } else {
      add(2 * t + 2, tc, tr, p, x);
    }
    s[t] = max(s[2 * t + 1], s[2 * t + 2]);
  }

  int get(int t, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
      return s[t];
    }
    int tc = tl + (tr - tl) / 2;
    int ls = 0, rs = 0;
    if (l < tc) {
      ls = get(2 * t + 1, tl, tc, l, min(r, tc));
    } 
    if (r > tc) {
      rs = get(2 * t + 2, tc, tr, max(l, tc), r);
    }
    return max(ls, rs);
  }
};

int get_index(SegmentTree& st, int l, int n, int val) {
  if (st.get(l, n) <= val) return -1;
  int r = n;
  int index, mid;
  while (r > l) {
    mid = r - (r - l) / 2;
    if (st.get(l, mid) > val) {
      index = l;
      r = mid - 1;
    } else {
      l = mid;
    }
  }
  return index;
}

void Solve() {
  int n; cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  vector<int> ans(n, -1);
  stack<int> even_stack;
  stack<int> odd_stack;
  for (int i = n - 1; i >= 0; --i) {
    if (i % 2 == 0) {
      while (!even_stack.empty() && v[i] >= v[even_stack.top()]) {
        even_stack.pop();
      }
      if (even_stack.empty()) {
        ans[i] = -1;
      }
      else ans[i] = even_stack.top() - i;
      even_stack.push(i);
    } else {
      while (!odd_stack.empty() && v[i] >= v[odd_stack.top()]) {
        odd_stack.pop();
      }
      if (odd_stack.empty()) {
        ans[i] = -1;
      }
      else ans[i] = odd_stack.top() - i;
      odd_stack.push(i);
    }
  }
  print(ans);
}

signed main() {
  MakeFast();
  int t = 1;
  //cin >> t;
  while (t--) {
    Solve();
  }
}