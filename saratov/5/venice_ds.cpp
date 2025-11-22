#include <iostream>
#include <vector>
#include <cstdint>
#include <set>

#define int int64_t
#define rep(i, k) for (int i = 0; i != k; ++i)

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

class VeniceSet {
public:
    VeniceSet() {}
    void inc(int x) {add += x;}
    void insert(int x) {data.insert(x - add);}
    void erase(int x) {data.erase(x - add);}
    bool check(int x) {return data.find(x - add) != data.end();}
    size_t size() {return data.size();}
private:
    set<int> data;
    int add = 0;
};

class ResettableArray {
public:
    void assign_all(int x) {
        full = x;
        last_full_upd = timer++;
    }
    void assign(int ind, int x) {
        data[ind] = x;
        last_upd[ind] = timer++;
    }
    int get(int x) {
        if (last_full_upd > last_upd[x]) return full;
        return data[x];
    }
    void push_back(int x) {
        data.push_back(x);
        last_upd.push_back(timer++);
    }
    void pop_back() {
        data.pop_back();
        last_upd.pop_back();
    }
private:
    vector<int> data;
    vector<int> last_upd;
    int full;
    int last_full_upd;
    int timer;
};

signed main() {
    
}