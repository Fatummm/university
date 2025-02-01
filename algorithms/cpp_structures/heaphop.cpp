#include <iostream>
#include <vector>
#include <stdexcept>


#define SEPARATOR ' '

template <typename T, typename comparator = std::less<>>
class Heap {
private:
    std::vector<T> data;
    size_t size = 0;
    comparator cmp = comparator{};

public:
    void Insert(T);
    void SiftUp(size_t);
    void SiftDown(size_t);
    T Top();
    T Pop();
    size_t Left(size_t);
    size_t Parent(size_t);
    size_t Right(size_t);

    T operator [] (size_t);
    size_t Size();

};

template <typename T, typename comparator>
size_t Heap<T, comparator>::Left(size_t i) {
    size_t res = 2 * i + 1;
    if (res >= size) throw std::out_of_range("There is no left child");
    return res;
}

template <typename T, typename comparator>
size_t Heap<T, comparator>::Right(size_t i) {
    size_t res = 2 * i + 2;
    if (res >= size) throw std::out_of_range("There is no right child");
    return res;
}

template <typename T, typename comparator>
size_t Heap<T, comparator>::Parent(size_t i) {
    if (i == (size_t)0) throw std::out_of_range("There is no parent");
    size_t res = (i - 1) / 2;
    return res;
}

template <typename T, typename comparator>
void Heap<T, comparator>::Insert(T value) {
    data.push_back(value);
    SiftUp(size++);
}

template <typename T, typename comparator>
void Heap<T, comparator>::SiftUp(size_t i) {
    while (i > 0 && cmp(data[i], data[(i - 1)/2])) {
        std::swap(data[i], data[(i - 1)/2]);
        i = (i - 1) / 2;
    }
}

template <typename T, typename comparator>
T Heap<T, comparator>::operator [] (size_t index) {
    if (index >= size)  throw std::out_of_range("What a misery");
    else return data[index];
}

template <typename T, typename comparator>
std::ostream& operator << (std::ostream& out, Heap<T, comparator> hp) {
    for (size_t i = 0; i != hp.Size(); ++i) {
        if (i != 0) out << SEPARATOR;
        out << hp[i];
    }
    return out;
}

template <typename T, typename comparator>
size_t Heap<T, comparator>::Size() {
    return size;
}

template <typename T, typename comparator>
T Heap<T, comparator>::Top() {
    if (size == 0) throw std::out_of_range("The heap is empty");
    else return data.front();
}

template <typename T, typename comparator>
T Heap<T, comparator>::Pop() {
    if (size == 0) throw std::out_of_range("The heap is empty");
    T elem = data.front();
    std::swap(data.front(), data.back());
    data.resize(--size);
    SiftDown(0);
    return elem;
}

template <typename T, typename comparator>
void Heap<T, comparator>::SiftDown(size_t index) {
    try {
        size_t cur = index;
        if (cmp(data[Left(index)], data[cur])) cur = Left(index);

        if (cmp(data[Right(index)], data[cur])) cur = Right(index);

        if (cur != index) {
            std::swap(data[index], data[cur]);
            SiftDown(cur);
        }
    } catch (...) {}
    
}

int main() {
    Heap<int> hp;
    hp.Insert(3);
    hp.Insert(5);
    hp.Insert(2);
    hp.Insert(4);
    hp.Insert(7);
    hp.Pop();
    hp.Pop();
    hp.Insert(8);
    hp.Insert(11);
    hp.Insert(0);
    std::cout << hp << std::endl;
}