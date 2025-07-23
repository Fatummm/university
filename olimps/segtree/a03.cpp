#include <vector>
#include <iostream>
#include <cmath>
#include <cstdint>

#define int int64_t

int get_left(int i) { return i * 2;}
int get_right(int i) { return 2 * i + 1;}

// pair: min, max
void build(std::vector<int>& src, std::vector<std::pair<int, int>>& segtree) {
    if (log2(src.size()) != int(log2(src.size()))) {
        src.resize(int(pow(2, int(log2(src.size())) + 1)));
    }
    segtree.resize(src.size() * 2, {INT64_MAX, INT64_MIN});
    for (int i = src.size(); i != segtree.size(); ++i) {
        segtree[i] = {src[i - src.size()], src[i - src.size()]};
    }
    for (int i = src.size() - 1; i > 0; --i) {
        segtree[i].first = std::min(segtree[get_left(i)].first, segtree[get_right(i)].first);
        segtree[i].second = std::max(segtree[get_left(i)].second, segtree[get_right(i)].second);
    }
}

int get_max(std::vector<std::pair<int, int>>& segtree, int node, int left, int right, int qleft, int qright) {
    if (qleft >= right || qright <= left) return INT64_MIN;
    if (qleft <= left && right <= qright) return segtree[node].second;
    int mid = (right - left) / 2 + left;
    return std::max(get_max(segtree, get_left(node), left, mid, qleft, qright),
                    get_max(segtree, get_right(node), mid, right, qleft, qright));
}

int get_min(std::vector<std::pair<int, int>>& segtree, int node, int left, int right, int qleft, int qright) {
    if (qleft >= right || qright <= left) return INT64_MAX;
    if (qleft <= left && right <= qright) return segtree[node].first;
    int mid = (right - left) / 2 + left;
    return std::min(get_min(segtree, get_left(node), left, mid, qleft, qright),
                    get_min(segtree, get_right(node), mid, right, qleft, qright));
}

void update(std::vector<std::pair<int, int>>& segtree, int node, int left, int right, int target, int x) {
    if (left == target && target + 1 == right) segtree[node] = {x, x};
    else {
        int mid = (right - left) / 2 + left;
        if (target >= mid) update(segtree, get_right(node), mid, right, target, x);
        else update(segtree, get_left(node), left, mid, target, x);
        segtree[node].first = std::min(segtree[get_left(node)].first, segtree[get_right(node)].first);
        segtree[node].second = std::max(segtree[get_left(node)].second, segtree[get_right(node)].second);
    }
}

signed main() {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::vector<int> a(100'000, 0);
    for (int n = 0; n != a.size(); ++n) {
        a[n] = (int(pow(n + 1 , 2)) % 12345) + (int(pow(n + 1, 3)) % 23456);
    }
    std::vector<std::pair<int, int>> st;
    build(a, st);
    int k; std::cin >> k;
    for (int i = 0; i != k; ++i) {
        int x, y; std::cin >> x >> y;
        if (x > 0) {
            std::cout << get_max(st, 1, 0, a.size(), x - 1, y) - get_min(st, 1, 0, a.size(), x - 1, y) << '\n';
        }
        else {
            update(st, 1, 0, a.size(), -x - 1, y);
        }
    }
}