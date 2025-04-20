#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i != n; ++i) {
        int number; std::cin >> number;
        for(int j = 0; j != number; ++j) {
            int tmp; std::cin >> tmp;
            adj[i].push_back(tmp);
        }
    }
    std::vector<std::vector<int>> ans;

}