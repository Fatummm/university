#include <iostream>
#include <vector>
// сумма на отрезках

int get_left(int i) {
    return 2*i;
}

int get_right(int i) {
    return 2 * i + 1;
}

int get_parent(int i) {
    return i / 2;
}

void update(std::vector<int>& segtree, int node, int left, int right, int elem, int x) {
    std::cout << left << ' ' << right << '\n';
    if (elem == left && elem + 1 == right) segtree[node] = x;
    else {
        int mid = (right - left) / 2 + left;
        if (elem >= mid) update(segtree, get_right(node), mid, right, elem, x);
        else update(segtree, get_left(node), left, mid, elem, x);
        segtree[node] = segtree[get_left(node)] + segtree[get_right(node)];
    }
}

int get(std::vector<int>& segtree, int node, int left, int right, int qleft, int qright) {
    if (qleft >= right || qright <= left) return 0;
    if (left >= qleft && right <= qright) return segtree[node];
    int mid = (left + right) / 2;
    return get(segtree, get_left(node), left, mid, qleft, qright) + 
           get(segtree, get_right(node), mid, right, qleft, qright);
}

void build(std::vector<int>& source, std::vector<int>& segtree, int left, int right) {
    segtree.resize(source.size() * 2, 0);
    for (int i = 0; i != source.size(); ++i) {
        segtree[source.size() + i] = source[i];
    }
    for (int i = source.size() - 1; i > 0; --i) {
        segtree[i] = segtree[get_left(i)] + segtree[get_right(i)];
    }
}


template <typename T>
void print_vec(const std::vector<T>& v) {
    for (int i = 0; i != v.size(); ++i) {
        if (i != 0) std::cout << ' ';
        std::cout << v[i];
    }
    std::cout << '\n';
}

int main() {
    int n = 10;
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    v.resize(16, 0);
    std::vector<int> st;
    build(v, st, 0, v.size());
    update(st, 1, 0, v.size(), 4, 7);
    print_vec(st);
    std::cout << get(st, 1, 0, v.size(), 3, 8) << '\n';
}