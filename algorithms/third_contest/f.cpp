#include <iostream>
#include <vector>

struct Node {
    int left;
    int right;
    int value;
    Node(int val, int l, int r): value(val), left(l), right(r) {}
};

void InOrderWalk(std::vector<Node>& v, int node) {
    if (v[node].left != -1) InOrderWalk(v, v[node].left);
    std::cout << v[node].value << ' ';
    if (v[node].right != -1) InOrderWalk(v, v[node].right);
}

void PreOrderWalk(std::vector<Node>& v, int node) {
    std::cout << v[node].value << ' ';
    if (v[node].left != -1) PreOrderWalk(v, v[node].left);
    if (v[node].right != -1) PreOrderWalk(v, v[node].right);
}

void PostOrderWalk(std::vector<Node>& v, int node) {
    if (v[node].left != -1) PostOrderWalk(v, v[node].left);
    if (v[node].right != -1) PostOrderWalk(v, v[node].right);
    std::cout << v[node].value << ' ';
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Node> v;
    for (int i = 0; i != n; ++i) {
        int val, left, right; std::cin >> val >> left >> right;
        v.push_back(Node(val, left, right));
    }
    InOrderWalk(v, 0); std::cout << '\n';
    PreOrderWalk(v, 0); std::cout << '\n';
    PostOrderWalk(v, 0); std::cout << '\n';

}