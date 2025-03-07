#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<int> stack;
    int current_max;
    int n; std::cin >> n;
    std::string s;
    std::vector<int> ans;
    for (int i = 0; i != n; ++i) {
        std::cin >> s;
        if (s == "push") {
            int x; std::cin >> x;
            if (stack.empty()) {
                stack.push_back(x);
                current_max = x;
            }
            else {
                if (x > current_max) {
                    stack.push_back(2 * x - current_max);
                    current_max = x;
                }
                else stack.push_back(x);
            }
            
        }
        else if (s == "max") ans.push_back(current_max);
        else {
            if (stack.back() > current_max) {
                current_max = 2 * current_max - stack.back();
                stack.pop_back();
            }
            else stack.pop_back();
        }
    }
    for (int i = 0; i != ans.size(); ++i) {
        std::cout << ans.at(i) << '\n';
    }
}