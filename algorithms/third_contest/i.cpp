#include <vector>
#include <iostream>

struct Node {
    int left = -1;
    int right = -1;
    long long value = 0;
    Node() = default;
    Node(long long v, int l, int r): value(v), left(l), right(r) {}
};

long long findMax(std::vector<Node>& v, int u) {
    if (v[u].left == -1 && v[u].right == -1) return v[u].value;
    else if (v[u].left == -1) return std::max(findMax(v, v[u].right), v[u].value);
    else if (v[u].right == -1) return std::max(findMax(v, v[u].left), v[u].value);
    else return std::max(std::max(findMax(v, v[u].right), findMax(v, v[u].left)), v[u].value);
}

long long findMin(std::vector<Node>& v, int u) {
    if (v[u].left == -1 && v[u].right == -1) return v[u].value;
    else if (v[u].left < 0) return std::min(findMin(v, v[u].right), v[u].value);
    else if (v[u].right < 0) return std::min(findMin(v, v[u].left), v[u].value);
    else return std::min(std::min(findMin(v, v[u].right), findMin(v, v[u].left)), v[u].value);
}

int main() {
    int n; std::cin >> n;
    std::vector<Node> v(n);
    for (int i = 0; i != n; ++i) {
        long long val, left, right; std::cin >> val >> left >> right;
        v[i] = Node(val, left, right);
    }   
    bool flag = true;
    for (int i = 0; i != n; ++i) {
        long long cur = v[i].value;
        if (v[i].right >= 0 && findMin(v, v[i].right) < cur) flag = false;
        if (v[i].left >= 0 && findMax(v, v[i].left) >= cur) flag = false;
    }
    
    std::cout << (flag ? "CORRECT\n" : "INCORRECT\n");
}