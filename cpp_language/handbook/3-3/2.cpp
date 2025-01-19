#include <iostream>
#include <vector>

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) return last;
    Iter cur_last = first; ++first;
    while (first != last) {
        if (*cur_last != *first) {
            ++cur_last;
            *cur_last = *first;
        }
        ++first;
    }
    return (cur_last != last) ? ++cur_last : cur_last;
}

int main() {
    std::vector<int> v = {5, 5, 5, 3, 2, 2, 5, 9, 1};
    v = {};
    auto iter = Unique(v.begin(), v.end());
    for (auto elem: v) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl <<  (iter == v.end()) <<'\n';
}