#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int get_left(int i) {
    return i * 2;
}

int get_right(int i) {
    return i * 2 + 1;
}

void build(vector<int>& src, vector<int>& segtree) {
    if (static_cast<int>(log2(src.size())) != log2(src.size())) {
        src.resize(static_cast<int>(pow(2, static_cast<int>(log2(src.size())) + 1)));
    }
    segtree.resize(src.size() * 2);

    for (int i = src.size(); i != segtree.size(); ++i) {
        segtree[i] = src[i - src.size()];
    }
    for (int i = src.size() - 1; i > 0; --i) {
        segtree[i] = segtree[get_left(i)] + segtree[get_right(i)];
    }
}

int get(vector<int>& segtree, int node, int left, int right, int qleft, int qright) {
    if (qright <= left || qleft >= right) return 0;
    if (left >= qleft && qright >= right) return segtree[node];
    int mid = (right + left) / 2;
    return get(segtree, get_left(node), left, mid, qleft, qright) +
        get(segtree, get_right(node), mid, right, qleft, qright);
}

signed main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i != n; ++i) cin >> v[i];
    vector<int> st;
    build(v, st);
    int cnt = 0;
    for (int i = 1; i != n; ++i) {
        if (get(st, 1, 0, v.size(), 0, i) == get(st, 1, 0, v.size(), i, v.size())) {
            ++cnt;
        }
    }
    cout << cnt << '\n';
}
