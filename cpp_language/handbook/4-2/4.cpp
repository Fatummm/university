#include <cstddef>
#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
class Deque {
private:
    std::vector<T> head;
    std::vector<T> tail;

public:
    bool Empty() const {
        return head.empty() && tail.empty();
    }

    size_t Size() const {
        return head.size() + tail.size();
    }

    void Clear() {
        head.clear();
        tail.clear();
    }

    const T& operator [] (size_t i) const {
        if (i >= head.size()) return tail[i - head.size()];
        return head[head.size() - i - (size_t)1];
    }

    T& operator [] (size_t i) {
        if (i >= head.size()) return tail[i - head.size()];
        return head[head.size() - i - (size_t)1];
    }

    const T& At(size_t i) const {  // throws std::out_of_range on incorrect index
        if (i >= head.size() + tail.size()) throw std::out_of_range("WTF, bruh");
        if (i >= head.size()) return tail[i - head.size()];
        return head[head.size() - i - (size_t)1];
    }
    T& At(size_t i) { // throws std::out_of_range on incorrect index
        if (i >= head.size() + tail.size()) throw std::out_of_range("WTF, bruh");
        if (i >= head.size()) return tail[i - head.size()];
        return head[head.size() - i - (size_t)1];
    }

    const T& Front() const {
        if (head.empty()) return tail.front();
        return head.back();
    }

    T& Front() {
        if (head.empty()) return tail.front();
        return head.back();
    }

    const T& Back() const {
        if (tail.empty()) return head.front();
        return tail.back();
    }

    T& Back() {
        if (tail.empty()) return head.front();
        return tail.back();
    }

    void PushFront(const T& elem) {
        head.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail.push_back(elem);
    }
};

template <typename T>
std::ostream& operator << (std::ostream& out, const Deque<T>& d) {
    for (size_t i = 0; i != d.Size(); ++i) {
        if (i != 0) out << ' ';
        out << d.At(i);
    }
    return out;
}

int main() {
    class Deque<int> d;
    d.PushBack(4);
    d.PushBack(5);
    d.PushFront(3);
    d.PushFront(2);
    d.PushFront(1);
    std::cout << d.At(5) << '\n';
    std::cout << d << '\n';
}
