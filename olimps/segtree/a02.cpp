#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

#define int int64_t

int get_left(int i) {
    return i * 2;
}

int get_right(int i) {
    return i * 2 + 1;
}

void build(std::vector<int>& src, std::vector<int>& segtree) {
    if (log2(src.size()) != int(log2(src.size()))) {
        src.resize(int(pow(2, int(log2(src.size())) + 1)));
    }
    segtree.resize(src.size() * 2);
    for (int i = src.size(); i != segtree.size(); ++i) {
        segtree[i] = src[i - src.size()];
    }

    for (int i = src.size() - 1; i > 0; --i) {
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

void update(std::vector<int>& segtree, int node, int left, int right, int aim, int x) {
    if (left == aim && aim + 1 == right) segtree[node] = x;
    else {
        int mid = (right - left) / 2 + left;
        if (aim >= mid) update(segtree, get_right(node), mid, right, aim, x);
        else update(segtree, get_left(node), left, mid, aim, x);
        segtree[node] = segtree[get_left(node)] + segtree[get_right(node)];
    }
}

signed main() {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, m; std::cin >> n >> m;
    std::vector<int> v(n);
    for (int i = 0; i != n; ++i) std::cin >> v[i];
    std::vector<int> st;
    build(v, st);
    int t, x ,y;
    
    for (int i = 0; i != m; ++i) {
        std::cin >> t >> x >> y;
        if (t == 0) {
            --x;
            std::cout << get(st, 1, 0, v.size(), x, y) << '\n';
        }
        else {
            --x;
            update(st, 1, 0, v.size(), x, y);
        }
    }
}