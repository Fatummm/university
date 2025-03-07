#include <iostream>
#include <vector>
#include <string>

#define ll long long
#define ull unsigned long long

struct Item {
    std::string key = "";
    long long value = -1;
    bool is_empty = true;
    Item(std::string s, ll n): key(s), value(n), is_empty(false) {}
    Item() = default;
};

std::string getLog(std::string key, ll hash, std::string command, std::string result, int tmp = -1, int probing = -1) {
    std::string s;
    s += "key=" + key + " hash=" + std::to_string(hash) + " operation=" + command + " ";
    s += "result=" + result + (probing == -1 ? "" : " linear_probing=" + std::to_string(probing)) + 
    (tmp == -1 ? "" : " value=" + (tmp == -2 ? "no_key" : (tmp == -3 ? "removed" : std::to_string(tmp))));
    return s;
}

ull pow(ull power, ull p, ull q) {
    ull res = 1;
    for (ull i = 0; i != power; ++i) {
        res = (res * p) % q;
    }
    return res;
}

ull hashString(std::string s, int p, int q) {
    ull res = 0;    
    for (ull i = 0; i != s.size(); ++i) {
        res = res + (ull)(s[i] - 'a' + 1) * pow(i, p, q);
        //std::cout << (ull)s[i] << '\n';
    }   
    return (res + q) % q;
}

int main() {
    ull q, p, n; std::cin >> q >> p >> n;
    std::vector<Item> v(q);
    std::vector<std::string> ans;
    for (int i = 0; i != n; ++i) {
        std::string command; std::cin >> command;
        std::string elem; std::cin >> elem;
        if (command == "PUT") {
            
            long long x; std::cin >> x;
            ull index =  hashString(elem, p, q);
            if (v[index].is_empty || v[index].value == -1) {
                
                v[index] = Item(elem, x);
                ans.push_back(getLog(elem, index, command, "inserted", x));
            }
            else {
                for (ull j = (index + 1) % q; j != index; j = (j + 1) % q) {
                    if (v[j].value == -1) {
                        v[j] = Item(elem, x);
                        ans.push_back(getLog(elem, index, command, "collision", x, j));
                        break;
                    }
                    if ((j + 1) % q == index) ans.push_back(getLog(elem, index, command, "overflow"));
                }
            }
        }
        else if (command == "GET") {
            ull index = hashString(elem, p, q);
            //std::cout << v[index].key << "-\n";
            if (v[index].key == elem) ans.push_back(getLog(elem, index, command, "found", v[index].value));
            else {
                for (ull j = (index + 1) % q; j != index; j = (j + 1) % q) {
                    // if (v[i].is_empty && v[index].value != -1) {
                    //     ans.push_back(getLog(elem, index, command, "collision", -2, j));
                    //     break;
                    // }
                    // else if (v[i].is_empty && v[index].value == -1) {
                    //     ans.push_back(getLog(elem, index, command, "no_key"));
                    //     break;
                    // }
                    if (v[j].key == elem) {
                        ans.push_back(getLog(elem, index, command, "collision", v[j].value, j));
                        break;
                    }
                    if ((j + 1) % q == index) {
                        if (v[index].value == -1) {
                            ans.push_back(getLog(elem, index, command, "no_key"));
                        }
                        else ans.push_back(getLog(elem, index, command, "collision", -2, j));
                        break;
                    }
                }
            }
        }
        else { // DEL
            ull index = hashString(elem, p, q);
            if (v[index].key == elem) {
                ans.push_back(getLog(elem, index, command, "removed"));
                v[index].key = "";
                v[index].value = -1;
            }
            else {
                for (ull j = (index + 1) % q; j != index; j = (j + 1) % q) {
                    // if (v[i].is_empty) {
                    //     ans.push_back(getLog(elem, index, command, "collision", -2, i));
                    //     break;
                    // }
                    if (v[j].key == elem) {
                        ans.push_back(getLog(elem, index, command, "collision", -3, j));
                        v[index].key = "";
                        v[index].value = -1;
                        break;
                    }
                    if ((j + 1) % q == index) {
                        if (v[index].value == -1) ans.push_back(getLog(elem, index, command, "no_key"));
                        else ans.push_back(getLog(elem, index, command, "collision", -2, j));
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i != ans.size(); ++i) {
        std::cout << ans[i] << '\n';
    }
}