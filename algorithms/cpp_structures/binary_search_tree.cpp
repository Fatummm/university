#include <vector>
#include <iostream>

template <typename T>
struct Node {
    T value;
    Node * left = nullptr;
    Node * right = nullptr;
    Node * parent = nullptr;

    Node(T val): value(val) {}
    Node(T val, Node * p): value(val), parent(p) {}

};


template <typename T>
class BST {
private:
    Node<T> * root = nullptr;
    size_t size = 0;
public:
    BST(T val) {
        root = new Node<T>(val);
        size = 1;
    }
    BST() = default;

    ~BST() {
        DeleteRoot();
    }

    void DeleteNode(Node<T> * x) {
        if (x->left == nullptr && x->right == nullptr) {
            Node<T> * pr = x->parent;
            if (pr != nullptr && )
            delete x;
            x = nullptr;
        }
    }
    Node<T> * GetRoot() {
        return root;
    }
    void PrintInOrder(Node<T> * x) {
        if (x != nullptr) {
            PrintInOrder(x->left);
            std::cout << x->value << ' ';
            PrintInOrder(x->right);
        }
    }

    void Insert(T val) {
        ++size;
        Node<T> * x = root;
        Node<T> * par = nullptr;
        while (x != nullptr) {
            par = x;
            if (x->value > val) {
                x = x->left;
            }
            else x = x->right;
        }
        x = new Node<T>(val);
        x->parent = par;
        if (par != nullptr && par->value > x->value) par->left = x;
        else if (par != nullptr) par->right = x;
    }

    Node<T> * GetMin(Node<T> * x) {
        while (x->left != nullptr) x = x->left;
        return x;
    }
};

int main() {
    BST<int> bst;
    bst.Insert(1);
    bst.Insert(4);
    bst.Insert(7);
    bst.Insert(2);
    bst.Insert(9);
    bst.Insert(5);

    //bst.PrintInOrder(bst.GetRoot());
    std::cout << bst.GetMin(bst.GetRoot())->value;
}