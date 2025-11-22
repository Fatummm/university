#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
using namespace std;

signed main() {
    ofstream f("test.txt");
    int n = 200'000;
    f << 1 << '\n' << n << '\n';
    for (int i = 0; i != n; ++i) {
        f << i << ' ';
    }
}