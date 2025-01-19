#include <iostream>
#include <set>
#include <vector>
#include <cstdint>
#include <queue>

int main() {
    uint64_t n, k; std::cin >> n >> k;
    std::vector<int64_t> ans;
    std::multiset<int64_t> mls;
    std::queue<int64_t> q;
    for (uint64_t i = 0; i != n; ++i) {
        int64_t x; std::cin >> x;
        q.push(x);
        mls.insert(x);
        if (q.size() == k + 1) {
            int64_t tmp = q.front(); q.pop();
            std::multiset<int64_t>::iterator it = mls.find(tmp);
            mls.erase(it);
        }
        if (q.size() == k) {
            ans.push_back(*mls.begin());
        }
    }
    for (int64_t elem: ans) {
        std::cout << elem << std::endl;
    }
}