#include <iostream>
#include <vector>
#include <stdexcept>
#include <tuple>

#define SEPARATOR ' '

template <typename T, typename comparator>
class Heap {
private:
    std::vector<T> data;
    size_t size = 0;
    comparator cmp;

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
        try {if (cmp(data[Left(index)], data[cur])) cur = Left(index);} catch (...) {}

        try {if (cmp(data[Right(index)], data[cur])) cur = Right(index);} catch (...) {}
        // std::cout << "\nData:\n";
        // for (size_t i = 0; i != data.size(); ++i) {
        //     std::cout << data[i] << ' ';
        // }
        // std::cout << "\n-----\n";
        if (cur != index) {
            std::swap(data[index], data[cur]);
            SiftDown(cur);
        }
    } catch (...) {}
}

struct Process {
    unsigned long long time = 0;
    unsigned long long number;
    Process(unsigned long long n): number(n) {}
    Process(unsigned long long n, unsigned long long t): number(n), time(t) {}
    Process() = default;
};

bool operator < (const Process& lhs, const Process& rhs) {
    return std::tie(lhs.time, lhs.number) < std::tie(rhs.time, rhs.number);
}

int main() {
    Heap<Process, std::less<Process>> hp;
    unsigned long long n, m; std::cin >> n >> m;
    for (unsigned long long i = 0; i != n; ++i) {
        hp.Insert(Process(i));
    }
    std::vector<Process> ans;
    for (unsigned long long i = 0; i != m; ++i) {
        unsigned long long p; std::cin >> p;
        ans.push_back(Process(hp.Top().number, hp.Top().time));
        Process tmp = hp.Pop();
        hp.Insert(Process(tmp.number, tmp.time + p));
    }
    for (unsigned long long i = 0; i != m; ++i) {
        std::cout << ans[i].number << ' ' << ans[i].time << '\n';
    }
}