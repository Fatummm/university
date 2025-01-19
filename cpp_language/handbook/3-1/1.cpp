#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <forward_list>
#include <array>

template <class Container>
void Print(const Container& container, std::string delimiter) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (it != container.begin()) std::cout << delimiter;
        std::cout << *it;
    }
}

int main() {
    std::array<int, 4> data1 = {1, 2, 3, 4};
    std::vector<int, std::allocator<int>> data2 = {1, 2, 3, 4};
    Print(data1, ", ");  // 1, 2, 3, 4
}