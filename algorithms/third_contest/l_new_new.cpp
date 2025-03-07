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

std::string getLog(std::string key, ll hash, std::string command, std::string result, long long tmp = -1, int probing = -1) {
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
    for (int k = 0; k != n; ++k) {
        std::string command; std::cin >> command;
        std::string elem; std::cin >> elem;
        if (command == "PUT") {
            long long x; std::cin >> x;
            ull hash = hashString(elem, p, q);

            if (v[hash].is_empty || v[hash].value == -1) {
                v[hash] = Item(elem, x);
                ans.push_back(getLog(elem, hash, command, "inserted", x)); // 1
                continue;
            }

            for (ull i = (hash + 1) % q; i != hash; i = (i + 1) % q) {
                if (v[i].value == -1) {
                    v[i] = Item(elem, x);
                    ans.push_back(getLog(elem, hash, command, "collision", x, i)); // 2
                    break;
                }
                if ((i + 1) % q == hash) {
                    ans.push_back(getLog(elem, hash, command, "overflow")); // 3
                }
            }
        }
        else if (command == "GET") {
            ull hash = hashString(elem, p, q);
            if (v[hash].key == elem) {
                ans.push_back(getLog(elem, hash, command, "found", v[hash].value)); // 1
                continue;
            }
            
            // 2-4
            for (ull i = (hash + 1) % q; i != hash; i = (i + 1) % q) {
                if (v[i].key == elem) {
                    ans.push_back(getLog(elem, hash, command, "collision", v[i].value, i)); // 2
                    break;
                }
                if ((i + 1) % q == hash && v[hash].is_empty == true) {
                    ans.push_back(getLog(elem, hash, command, "no_key")); // 4
                }
                else if ((i + 1) % q == hash) {
                    for (ull j = (hash + 1) % q; j != hash; j = (1 + j) % q) {
                        if (v[j].value == -1) {
                            ans.push_back(getLog(elem, hash, command, "collision", -2, j));// 3
                            break;
                        }
                        if (j + 1 == hash) {
                            ans.push_back(getLog(elem, hash, command, "collision", -2, hash));// 3
                        }  
                    }

                    
                }
            }
        }
        else { // DEL
            ull hash = hashString(elem, p, q);
            if (v[hash].key == elem) {
                v[hash].key = "";
                v[hash].value = -1;
                ans.push_back(getLog(elem, hash, command, "removed")); // 1
                continue;
            }

            for (ull i = (hash + 1) % q; i != hash; i = (i + 1) % q) {
                if (v[i].key == elem) {
                    v[i].key = "";
                    v[i].value = -1;
                    ans.push_back(getLog(elem, hash, command, "collision", -3, i)); // 2
                    break;
                }

                if ((i + 1) % q == hash && v[hash].value == -1) {
                    ans.push_back(getLog(elem, hash, command, "no_key"));
                }
                else if ((i + 1) % q == hash) {
                    for (ull j = (hash + 1) % q; j != hash; j = (1 + j) % q) {
                        if (v[j].value == -1) {
                            ans.push_back(getLog(elem, hash, command, "collision", -2, j));// 3
                            break;
                        }
                        if (j + 1 == hash) {
                            ans.push_back(getLog(elem, hash, command, "collision", -2, hash));// 3
                        } 
                    }
                }

            }
        }
    }
    for (int i = 0; i != ans.size(); ++i) {
        std::cout << ans[i] << '\n';
    }
}