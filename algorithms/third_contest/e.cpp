#include <iostream>
#include <vector>
#include <string>

#define MOD 1000000007
#define XTRA 263
#define ull long long

struct Node {
    std::string value;
    Node * next = NULL;
};


ull pow(ull power) {
    ull res = 1;
    for (ull i = 0; i != power; ++i) {
        res = (res * XTRA) % MOD;
    }
    return res;
}

ull hashString(std::string& s, int m) {
    ull res = 0;
    for (ull i = 0; i != s.size(); ++i) {
        res = res + ((ull)s[i] * pow(i));
        //std::cout << (ull)s[i] << '\n';
    }   
    return res % MOD % m;
}

int main() {
    int m, n; std::cin >> m >> n;
    std::vector<Node*> v(m, NULL);
    std::vector<std::vector<std::string>> ans;
    for (int i = 0; i != n; ++i) {
        std::string command; std::cin >> command;
        if (command == "add") {
            std::string s; std::cin >> s;
            ull hash = hashString(s, m);
            if (v[hash] == NULL) {
                v[hash] = new Node;
                v[hash]->value = s;
                continue;
            }
            Node * tmp = v[hash];
            bool enough = false;
            while (tmp != NULL) {
                if (tmp->value == s) enough = true;
                tmp = tmp->next;
            }
            if (!enough) {
                tmp = new Node;
                tmp->value = s;
                tmp->next = v[hash];
                v[hash] = tmp;
            }
        }
        else if (command == "del") {
            std::string s; std::cin >> s;
            ull hash = hashString(s, m);
            
            if (v[hash] != NULL && v[hash]->value == s) {
                Node * to_del = v[hash];
                v[hash] = v[hash]->next;
                delete to_del;
            }
            Node * tmp = v[hash];
            Node * parent = NULL;
            
            while (tmp != NULL && tmp->value != s){
                parent = tmp;
                tmp = tmp->next;
            }
            if (tmp != NULL) {
                parent->next = tmp->next;
                delete tmp;
            }
        }
        else if (command == "check") {
            ans.push_back({});
            ull index; std::cin >> index;
            Node * tmp = v[index];
            while (tmp != NULL) {
                ans.back().push_back(tmp->value);
                tmp = tmp->next;
            }
        }
        else if (command == "find") {
            std::string s; std::cin >> s;
            ull hash = hashString(s, m);
            Node * tmp = v[hash];
            while (tmp != NULL && tmp->value != s) tmp = tmp->next;
            if (tmp != NULL) ans.push_back({"yes"});
            else ans.push_back({"no"});
        }
    }
    for (int i = 0; i != ans.size(); ++i) {
        if (i != 0) std::cout << '\n';
        for (int j = 0; j != ans[i].size(); ++j) {
            if (j != 0) std::cout << ' ';
            std::cout << ans[i][j];
        }
    }
}