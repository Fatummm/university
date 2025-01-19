#include <iostream>
#include <deque>
#include <string>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::deque<std::string> deq;
    for (int i = 0; i != n; ++i) {
        std::string nick;
        std::string position;
        std::cin >> nick >> position;
        if (position == "top") deq.push_front(nick);
        else deq.push_back(nick);
    }
    std::cin >> n;
    std::vector<std::string> ans;
    for (int i = 0; i != n; ++i) {
        int x; std::cin >> x;
        ans.push_back(deq[x - 1]);
    }
    for (int i = 0; i != n; ++i) {
        if (i != 0) std::cout << '\n';
        std::cout << ans[i];
    }
}