#include <vector>
#include <string>
#include <iostream>
#include <cstdint>

using namespace std;

#define int int64_t

vector<int> get(int length, int calls, int start_number) {
    // length == 1
    if (length == 1 && calls != 0) throw 1;
    if (length == 1) return {start_number};

    // length == 2;
    if (length == 2 && calls == 2) return {start_number + 1, start_number};
    if (length == 2 && calls == 0) return {start_number, start_number + 1};
    if (length == 2) throw 'a';

    int l1 = length / 2;
    int l2 = length - l1;
    int c1 = calls / 2;
    int c2 = calls / 2;
    if (l2 > l1) {

    }
}

signed main() {
    int n, k; cin >> n >> k;
    if (k % 2 == 0 || k >= n * 2) {
        cout << -1 << '\n';
        return 0;
    }
    
}