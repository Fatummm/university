#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3};
    std::cout << v.size() << '\t' << v.capacity() << '\n';
    v.push_back(4);
    std::cout << v.size() << '\t' << v.capacity() << '\n';
}