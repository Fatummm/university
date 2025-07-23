#include <iostream>
#include <vector>
#include <set>
#include <cmath>

void solve() {
    int n; std::cin >> n;
    std::vector<int> v(n);
    std::vector<int> divisors;
    for (int i = 0; i != n; ++i) std::cin >> v[i];
    for (int i = 0; i != n - 1; ++i) {
        if (v[i+1] % v[i] == 0) continue;
        if (divisors.empty()) {
            for (int div = 1; div < static_cast<int>(sqrt(v[i]))+1; ++div) {
                if (v[i] % div == 0 && v[i+1] % (v[i] / div) == 0) {
                    divisors.push_back(div);
                    divisors.push_back(v[i] / div);
                }
            }
        }
        else {
            std::set<int> new_divisors;
            for (auto div : divisors) {
                if (v[i] % div == 0 && v[i+1] % (v[i] / div) == 0) {
                    new_divisors.insert(div);
                }
            }
            divisors.clear();
            std::copy(new_divisors.begin(), new_divisors.end(), std::back_inserter(divisors));
        }
    }
    if (divisors.size() == 0) std::cout << 666 << '\n'; 
    else std::cout << *divisors.begin() << '\n';
}

int main() {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t; std::cin >> t;
    for (int i = 0; i != t; ++i) {
        solve();
    }
}