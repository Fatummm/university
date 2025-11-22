#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

signed main() {
    srand(time(NULL));
    std::fstream f("test.txt");
    int t = 10;
    f << t << '\n';
    for (int i = 0; i != t; ++i) {
        // int n = rand() % 400 + 1;
        int n = 20;
        f << n << '\n';
        std::vector<int> v;
        for (int j = 0; j != n; ++j) {
            v.push_back(rand() % 5);
        }
        std::sort(v.begin(), v.end());
        for (int i = 0; i != v.size(); ++i) f << v[i] << ' ';
        f << '\n';
    }
    // f << 1 << '\n';
    // f << 1e5 << '\n';
    // for (int i = 0; i != 1e5; ++i) {
    //     f << rand() % 30 << ' ';
    // }
}