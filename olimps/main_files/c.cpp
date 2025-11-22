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

bool familiar(set<string>& s, set<string> st) {
  for (auto elem: s) {
    if (st.find(elem) != st.end()) return true;
  }
  return false;
}

void extend(set<string>& st, vector<string>& str) {
  for (auto elem: str) {
    st.insert(elem);
  }
}

void extend(set<string>& s1, set<string>& s2) {
  for (auto str: s2) {
    s1.insert(str);
  }
}

void Solve() {
  int n; cin >> n;
  vector<set<string>> contexts;
  DSU d(1000 + 1);
  rep(i, n) { // n
    int m; cin >> m;
    set<string> words;
    rep(j, m) {
      string s; cin >> s;
      words.insert(s);
    }
    //vector<int> added_contexts;
    int last = -1;
    rep(j, contexts.size()) { // n
      if (familiar(words, contexts[j])) {
        if (last == -1) {
          extend(contexts[j], words);
        } else {
          d.Unite(last, j);
        }
        last = j;
        //added_contexts.push_back(j);
      }
    }
    if (last == -1) {
      contexts.emplace_back(words.begin(), words.end());
    }
  }
  vector<set<string>> real_contexts(n);
  vector<int> really(n);
  
  rep(i, contexts.size()) {
    extend(real_contexts[d.GetRoot(i)], contexts[i]);
  }
  int cnt = 0, mx = 0;
  rep(i, real_contexts.size()) {
    if (real_contexts[i].empty()) continue;
    ++cnt;
    mx = max(mx, (int)real_contexts[i].size());
  }
  cout << cnt << ' ' << mx << '\n';
}

signed main() {
  MakeFast();
  int t = 1;
  //cin >> t;
  while (t--) {
    Solve();
  }
}