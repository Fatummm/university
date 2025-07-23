#include <vector>
#include <iostream>
#include <cmath>

#define int long long

int get_left(int i) {
    return i * 2;
}

int get_right(int i) {
    return i * 2 + 1;
}

int get_parent(int i) {
    return i / 2;
}

void build(std::vector<int>& source, std::vector<int>& segtree) {
    if (log2(source.size()) != static_cast<int>(log2(source.size()))) {
        source.resize(static_cast<int>(pow(2, static_cast<int>(log2(source.size())) + 1)));
    }
    segtree.resize(source.size() * 2, 0);
    for (int i = source.size(); i != segtree.size(); ++i) {
        segtree[i] = source[i - source.size()];
    }
    for (int i = source.size() - 1; i > 0; --i) {
        segtree[i] = segtree[get_left(i)] + segtree[get_right(i)];
    }
}

int get(std::vector<int>& segtree, int node, int left, int right, int qleft, int qright) {
    if (qleft >= right || qright <= left) return 0;
    if (qleft <= left && right <= qright) return segtree[node];
    int mid = (right - left) / 2 + left;
    return get(segtree, get_left(node), left, mid, qleft, qright) + 
    get(segtree, get_right(node), mid, right, qleft, qright);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, m; std::cin >> n >> m;
    std::vector<int> v(n);
    for (int i = 0; i != n; ++i) std::cin >> v[i];
    std::vector<int> st;
    build(v, st);
    for (int i = 0; i != m; ++i) {
        int l, r;
        std::cin >> l >> r; --l;
        std::cout << get(st, 1, 0, v.size(), l, r) << '\n';
    }
}