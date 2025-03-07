#include <vector>
#include <iostream>

struct Node {
    int color = 0;
    int left = -1;
    int right = -1;
    Node() = default;
    Node(int col, int l, int r):color(col), left(l), right(r) {}
};
// 1. корень - чёрный
// 2. у красной вершины - два чёрных потомка
// 3. чёрная высота

bool checkRoot(std::vector<Node>& v) {
    if (!v.empty()) return v[0].color == 0;
    return true;
}

bool checkRedNode(std::vector<Node>& v, int u) {
    if (v[u].color == 0) return true;
    if (v[u].left != -1 && v[v[u].left].color != 0) return false;
    if (v[u].right != -1 && v[v[u].right].color != 0) return false;
    return true;
}

int getBH(std::vector<Node>& v, int u) {
    if (u == -1) return 0;
    return getBH(v, v[u].left) + (int)(v[u].color == 0);
}

int main() {
    int n; std::cin >> n;
    std::vector<Node> v(n);
    for (int i = 0; i != n; ++i) {
        int colour, left = -1, right = -1, count = 0;
        std::cin >> count;
        if (count == 0) std::cin >> colour;
        else if (count == 1) std::cin >> left >> colour;
        else std::cin >> left >> right >> colour;
        v[i] = Node(colour, left, right);
    }
    bool flag = true;
    for (int i = 0; i != n; ++i) {
        if (!checkRedNode(v, i) || !checkRoot(v)) flag = false;
        if (getBH(v, v[i].left) != getBH(v, v[i].right)) flag = false;
        //std::cout << getBH(v, i) << ' ';
    }
    std::cout << (flag ? "YES\n" : "NO\n");
}