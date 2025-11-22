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
    void insert(int x) {
        if (check(x)) cout << 0 << '\n';
        else cout << 1 << '\n';
        data.insert(x - add);
    }
    void erase(int x) {
        if (check(x)) cout << 1 << '\n';
        else cout << 0 << '\n';
        data.erase(x - add);
    }
    bool check(int x) {return data.find(x - add) != data.end();}
private:
    set<int> data;
    int add = 0;
};

signed main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    VeniceSet vs;
    rep(i, t) {
        int n; cin >> n;
        int x; cin >> x;
        if (n == 1) vs.insert(x);
        else if (n == 2) vs.erase(x);
        else vs.inc(x); 
    }
}