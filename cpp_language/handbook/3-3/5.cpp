#include <algorithm>
#include <vector>
#include <iostream>

template <typename T>
void Process(const std::vector<T>& data) {
    std::vector<T> filtered(data.size());

    auto filteredLast = std::copy_if(
        data.begin(),
        data.end(),
        filtered.begin(),
        [](const T& x) { return x > 0; }
    );
    filtered.erase(filteredLast, filtered.end());
    for (auto it = filtered.begin(); it != filtered.end(); ++it) {
        std::cout << *it << ' ';
    }
    //PrintResults(filtered.begin(), filteredLast);
}

int main() {
    std::vector<int> v = {1, -2, 3, -4, -5, 10, -110};
    Process(v);
}