#include <iostream>
#include <vector>
#include <cstdint>

#define int int64_t

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int grandi[7500];

int mex(const vi& v) {
    vi got_it(v.size(), 0);
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] >= v.size()) continue;
        got_it[v[i]]++;
    }
    for (int i = 0; i < v.size(); ++i) {
        if (!got_it[i]) return i;
    }
    return v.size();
}

int get_grandi(int x) {
    if (grandi[x] != -1) return grandi[x];
    if (x <= 1) {
        grandi[x] = 0;
        return grandi[x];
    }
    vi v;
    for (int i = x - 1; i >= x/2; --i) v.push_back(get_grandi(i));
    grandi[x] = mex(v);
    return grandi[x];
}

int get_grandi(const vi& v) {
    return get_grandi(v[0]) ^ get_grandi(v[1]) ^ get_grandi(v[2]);
}

signed main() {
    for (int i = 0; i != 7500; ++i) grandi[i] = -1;
    int a, b, c; cin >> a >> b >> c;
    vi v = {a, b, c};
    cout << get_grandi(v) << '\n';
}
