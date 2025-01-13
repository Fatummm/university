#include <iostream>
#include <vector>
#include <string>

template <typename T, template <typename, typename> typename Container>
void Print(const Container<T, std::allocator<T>>& container, std::string delimiter) {
    for (const auto& it = std::cbegin(container); it != std::cend(container); ++it) {

    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 4};
    Print(data, ", ");  // 1, 2, 3, 4
}