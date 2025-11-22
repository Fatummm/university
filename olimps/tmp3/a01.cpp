#include <set>
#include <iostream>

int main() {
    int n; std::cin >> n;
    std::set<int> s;
    for (int i = 0; i != n; ++i) {
        int x; std::cin >> x;
        s.insert(x);
    }
    for (auto elem: s) {
        std::cout << elem << ' ';
    } std::cout << '\n';
}