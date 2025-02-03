#include <vector>
#include <iostream>

template <typename T>
class Node {
public:
    Node<T> * left;
    T key;
    Node<T> * right;

    Node(T val): key(val), left(nullptr), right(nullptr) {}

    void Delete() {
        if (left == nullptr && right == nullptr) delete this;
        else {
            if (left == nullptr) this->right->Delete();
            if (right == nullptr) this->left->Delete();
        }
    }

    void Insert(T val) {
        if (key > val && left != nullptr) {

        }
    }
};


template <typename T, typename Comparator = std::less<T>>
class BST {
private:
    Node<T> * root;
public:
    BST(T val) {
        root = new Node(val);
    }

    ~BST() {
        root->Delete();
    }


};

int main() {
    BST<int> tree(5);
}