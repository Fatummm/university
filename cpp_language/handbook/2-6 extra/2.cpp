#include <iostream>
#include <vector>
#include <string>

int main() {
    // Создаём вектор из трёх строк
    std::vector<std::string> words = {"apple", "banana", "cherry"};

    // Берём итератор на первый элемент
    auto it = words.begin();
    words.push_back("qiwi");
    std::cout << *it;
    
}