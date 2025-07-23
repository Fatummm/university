#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

#define int int64_t


signed main() {
    int n; std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i != n; ++i) std::cin >> v[i];
    std::sort(v.begin(), v.end());
    int it1 = 0;
    int it2 = v.size() / 2;
    std::vector<bool> used(n, false);
    int pockets = 0;
    while (it1 != n && it2 != n) {
        if (v[it2] / v[it1] >= 2 && !used[it1]) {
            used[it2] = true;
            ++pockets;
            it1++;
            it2++;
        }
        else if (v[it2] / v[it1] < 2 && !used[it1]) ++it2;
        else ++it1;
    }
    std::cout << n - pockets << '\n';    
}