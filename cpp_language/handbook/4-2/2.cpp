#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T>>
class Queue {
private:
    Container data;
public:
    Queue() = default;
    const T front() const {
        return *data.begin();
    }

    T front() {
        return *data.begin();
    }

    void pop() {
        data.pop_front();
    }

    void push(T val) {
        data.push_back(val);
    }

    size_t size() const {
        return data.size();
    }

    bool empty() const {
        return data.empty();
    }

    bool operator == (const Queue& other) const {
        return data == other.data;
    }

    bool operator != (const Queue& other) const {
        return !operator==(other);
    }
};


int main() {
    Queue<int> q;
    q.push(3);
    q.push(2);
    q.push(1);
    while (!q.empty()) {
        std::cout << q.front() << '\n';
        q.pop();
    }
}