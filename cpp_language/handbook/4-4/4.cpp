#include <iostream>
#include <vector>

template <typename T>
class AdvancedVector: public std::vector<T> {
private:

public:

    AdvancedVector() = default;

    template <typename Iter>
    AdvancedVector(Iter first, Iter last): std::vector<T>(first, last) {}
    T operator [] (int x) {
        while (x < 0) x += this->size();
        return this->at(x);
    }
    const T operator [] (int x) const {
        while (x < 0) x += this->size();
        return this->at(x);
    }
};

int main() {
    AdvancedVector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::cout << v[-10];
    std::cout << '\n';
}