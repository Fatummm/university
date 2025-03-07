#include <iostream>

template <typename T>
struct Node {
    T value;
    Node<T> * next;
    Node<T> * prev;
    Node(T val, Node<T> nxt, Node<T> prv): value(val), next(nxt), prev(prv) {}
    Node (T val): value(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class List {
public:
    Node<T> * head;
    Node<T> * tail;
    size_t size = 0;
private:

public:
    List() = default;
    List(T value) {
        head = new Node<T>(value);
        ++size;
        tail = head;
    }

    void Insert(T value, Node<T> * position) {
        ++size;
        Node<T> tmp = new Node<T>(value);
        tmp->prev = position->prev;
        tmp->next = position;
        position->prev = tmp;
    }

    void PushBack(T val) {
        ++size;
        Node<T> * tmp = new Node<T>(val);
        tail->next = tmp;
        tail = tmp;
    }

    void Print() {
        Node<T> tmp = head;
        for (size_t i = 0; i != size; ++i) {
            std::cout << tmp->value << ' ';
        }
    }
};

int main() {
    List<int> lst(5);
    lst.PushBack(3);
    lst.PushBack(1);
    lst.Insert(0, lst.head);
    lst.Print();
}