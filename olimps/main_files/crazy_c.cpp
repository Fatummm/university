#include <bits/stdc++.h>
#define ll long long
#define int ll
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) a.begin(), a.end()
#define vi vector<int>

using namespace std;

void MakeFast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class DSU {
public:
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(all(parent), 0);
    }
    int GetRoot(int x) {
        return parent[x] == x ? x : parent[x] = GetRoot(parent[x]);
    }
    void Unite(int x, int y) {
        x = GetRoot(x);
        y = GetRoot(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
    }
};

void Solve() {
    int n; 
    cin >> n;
    DSU dsu(n);

    unordered_map<string, int> word_owner;
    word_owner.reserve(n * 10);

    for (int i = 0; i < n; ++i) {
        int m; 
        cin >> m;
        unordered_set<string> unique_words;
        unique_words.reserve(m * 2);

        rep(j, m) {
            string s;
            cin >> s;
            if (!unique_words.insert(s).second) continue;

            auto it = word_owner.find(s);
            if (it == word_owner.end()) {
                word_owner[s] = i;
            } else {
                dsu.Unite(i, it->second);
            }
        }
    }
    vector<int> context_size(n, 0);
    for (auto &p : word_owner) {
        int root = dsu.GetRoot(p.second);
        context_size[root]++;
    }

    int cnt = 0, mx = 0;
    rep(i, n) {
        if (context_size[i] > 0) {
            ++cnt;
            mx = max(mx, context_size[i]);
        }
    }

    cout << cnt << ' ' << mx << '\n';
}

signed main() {
    MakeFast();
    Solve();
    return 0;
}
