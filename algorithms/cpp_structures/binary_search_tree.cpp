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
        while (size != 0) {
            DeleteNode(root);
        }
    }

    void DeleteNode(Node<T> * x) {
        // 0. Error
        if (x == nullptr) return;

        // 1. No children
        Node<T> * parent = x->parent;
        if (x->left == nullptr && x->right == nullptr) {
            if (parent->left == x) {
                parent->left = nullptr;
            }
            else parent->right = nullptr;
            --size;
            delete x;
            return;
        }

        // 2. only one child
        else if ((int)(x->left == nullptr) + (int)(x->right == nullptr) == 1) {
            if (x->left == nullptr) {
                Node<T> * parent = x->parent;
                if (parent == nullptr) {
                    root = x->right;
                    root->parent = nullptr;
                }
                if (parent != nullptr && parent->value > x->value) parent->left = x->right;
                else if (parent != nullptr) parent->right = x->right;
                if (parent != nullptr) x->right->parent = parent;
            }
            if (x->right == nullptr) {
                Node<T> * parent = x->parent;
                if (parent == nullptr) {
                    root = x->left;
                    root->parent = nullptr;
                }
                else if (parent->value > x->value) parent->left = x->left;
                else parent->right = x->left;
                x->left->parent = parent;
            }
            delete x;
            --size;
            return;
        }

        // 3. Two children
        Node<T> * left = x->left;
        Node<T> * right = x->right;
        Node<T> * success = GetSuccessor(x->right);
        if (right == success) {
            right->left = left;
            right->parent = parent;
            if (x != root) {
                if (x->parent->value > x->value) x->parent->left = right;
                else x->parent->right = right;
            }
            else root = right;
        }
        else {
            Node<T> * success_parent = success->parent;
            success_parent->left = success->right;
            if (parent != nullptr) {
                if (parent->value > x->value) parent->left = success;
                else parent->right = success;
                success->parent = parent;
            }
            else success->parent = nullptr;
            success->left = left;
            success->right = right;
        }
        delete x;
        --size;
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

    void PrintInOrder() {
        PrintInOrder(root);
    }

    Node<T> * GetSuccessor(Node<T> * x) {
        if (x->right != nullptr) return GetMin(x);
        return x;
    }

    void Insert(T val) {
        ++size;
        if (size == 1) {
            root = new Node<T>(val);
            return;
        }
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
        if (par != nullptr) {
            x->parent = par;
            if (par->value > x->value) par->left = x;
            else par->right = x;
        }
    }

    Node<T> * GetMin(Node<T> * x) {
        while (x->left != nullptr) x = x->left;
        return x;
    }

    Node<T> * GetMin() {
        return GetMin(root);
    }

    Node<T> * GetMax(Node<T> * x) {
        while (x->right != nullptr) x = x->right;
        return x;
    }

    Node<T> * Find(T val) {
        Node<T> * x = root;
        while (x != nullptr) {
            if (x->value == val) return x;
            if (x->value > val) x = x->left;
            else x = x->right;
        }
        return x;
    }

    Node<T> * GetMax() {
        return GetMax(root);
    }

    size_t Size() const {return size;}
};

int main() {
    BST<int> bst;
    bst.Insert(0);
    bst.Insert(4);
    bst.Insert(2);
    bst.Insert(1);
    bst.Insert(3);
    bst.Insert(7);
    bst.Insert(5);
    bst.Insert(6);
    bst.Insert(8);
    //std::cout << bst.Size();
    //bst.DeleteNode(bst.GetMax());
    //bst.DeleteNode(bst.GetMin());
    bst.DeleteNode(bst.Find(2));
    bst.PrintInOrder(); std::cout << '\n';
    //std::cout << bst.GetRoot()->value << std::endl;
}