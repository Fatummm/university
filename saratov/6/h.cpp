#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <numeric>
#include <queue>
#include <stack>
#include <deque>
#include <sstream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <random>
#include <list>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
using namespace __gnu_pbds;
using namespace std;
typedef tree<
    std::pair<int64_t, char>,
    null_type,
    std::less<>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set_p;
typedef tree<
    int64_t,
    null_type,
    std::less<>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;
#define int int64_t


const int64_t kInf = __INT64_MAX__ - 1000;
//const int kInf = 1e9 + 100;
const int kMod = 998244353;

template <typename T>
void Print(const T& v) {
  for (const auto& el : v) {
    cout << el << ' ';
  }
  cout << '\n';
}

void Print(const vector<pair<int, int>>& v) {
  for (const auto& el : v) {
    cout << "(" << el.first << ", " << el.second << ")" << ' ';
  }
  cout << '\n';
}

void MakeFast() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
}

bool cmp(int a, int b) {
  return a > b;
}

void solve() {
  int n, m;
  cin >> n >> m;
  std::map<int, vector<int>> skill;
  vector<int> sum(m, 0);
  rep(i, n) {
    int s, r;
    cin >> s >> r;
    --s;
    skill[s].push_back(r);
    sum[s] += r;
  }
  int maxLength = 0;
  vector<pair<int, int>> lenAndSum;
  rep(s, m) {
    std::sort(all(skill[s]), cmp);
    maxLength = std::max(maxLength, static_cast<int>(skill[s].size()));
    lenAndSum.emplace_back(static_cast<int>(skill[s].size()), sum[s]);
  }
  std::sort(all(lenAndSum));
  vector<int> sumWithLenLessOrEq(maxLength + 1, 0);
  int j = 0;
  for (int len = 1; len <= maxLength; ++len) {
    sumWithLenLessOrEq[len] = sumWithLenLessOrEq[len - 1];
    while (j < lenAndSum.size() && lenAndSum[j].first <= len) {
      sumWithLenLessOrEq[len] += lenAndSum[j].second;
      ++j;
    }
  }
//  Print(lenAndSum);
//  Print(sumWithLenLessOrEq);
  int ans = 0;
  int s = 0;
  for (int i = 1; i <= maxLength; ++i) {
    for (const auto& p : skill) {
      s += p.second[i - 1];
    }
    ans = std::max(ans, s - sumWithLenLessOrEq[i - 1]);
  }
  cout << ans << '\n';
}

signed main() {
  MakeFast();
  int t = 1;
//  cin >> t;
  while (t--) {
    solve();
  }
}
