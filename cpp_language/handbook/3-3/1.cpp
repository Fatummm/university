#include <vector>
#include <iostream>

template <typename T>
void Duplicate(std::vector<T>& v) {
    v.resize(v.size() * 2);
    std::copy(v.begin(), v.begin() + v.size() / 2, v.begin() + v.size() / 2);
}

int main() {
    std::vector<int> v = {1, 2, 3};
    Duplicate(v);
    for (auto elem: v) {
        std::cout << elem << ' ';
    }
}