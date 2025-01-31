#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct Node {
    std::map<std::string, Node> children;
};

class Tree {
private:
    Node root;

public:
    bool Has(const std::vector<std::string>& node) const;
    void Insert(const std::vector<std::string>& node);
    void Delete(const std::vector<std::string>& node);
};

// Ваш код будет вставлен сюда
void Tree::Insert(const std::vector<std::string>& node) {
    Node * current_folder = &root;
    for (std::string elem: node) {
        current_folder = &(current_folder->children[elem]);
    }
}

bool Tree::Has(const std::vector<std::string>& node) const {
    const Node * current_folder = &root;
    for (std::string elem: node) {
        if (current_folder->children.find(elem) != current_folder->children.end()) {
            current_folder = &(current_folder->children.at(elem));
        }
        else return false;
    }
    return true;
}

void Tree::Delete(const std::vector<std::string>& node) {
    Node * current_node = &root;
    for (std::vector<std::string>::const_iterator it = node.begin(); it != node.end(); ++it) {
        if (current_node->children.find(*it) != current_node->children.end() && it + 1 != node.end()) {
            current_node = &current_node->children[*it];
        }
    }
    current_node->children.erase(node.back());

}

int main() {
    Tree t;
    t.Insert({"1", "1.1"});
    t.Insert({"2", "2.1", "2.2"});
    t.Insert({"3"});
    t.Insert({"4"});
    t.Delete({"2", "2.1", "2.2"});
    std::cout << t.Has({"2", "2.1", "2.2"}) << std::endl;
}