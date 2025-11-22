#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <deque>
#include <cmath>

using namespace std;
#define int int64_t
#define rep(i, k) for (int i = 0; i != k; ++i)
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vpi = vector<pair<int, int>>;

int get_nearest_pow(int k) {
    return pow(2, static_cast<int>(log2(k)) + 1);
}

struct Segtree {
public:
    Segtree(vi& data): size(get_nearest_pow(data.size()) * 2) {
        st.resize(size, neutral);
        ans.resize(size);
        copy(data.begin(), data.end(), st.begin() + size / 2);
        rep(i, data.size()) {
            st[i + size/2] = data[i];
            ans[i + size/2] = data[i];
        }
        for (int i = st.size() / 2 - 1; i > 0; --i) {
            if (st[get_left(i)] > st[get_right(i)]) {
                st[i] = st[get_right(i)];
                ans[i] = get_right(i);
            }
        }
    }

    int get(int ql, int qr, int node = 1, int l = 0, int r = -1) {
        if (r == -1) r = st.size()/2;
        if (l >= r) return neutral;
        else if (qr <= l || r <= ql) return neutral;
        else if (ql <= l && qr >= r) return st[node];
        else return min(get(ql, qr, get_left(node), l, (l+r)/2), get(ql, qr, get_right(node), (l+r)/2, r));
    }
private:
    int get_left(int i) {return i * 2;}
    int get_right(int i) {return i * 2 + 1;}
    int get_parent(int i) {return i / 2;}

    vector<int> st;
    vector<int> ans;
    int size;
    int neutral = INT64_MAX;
};

int calc(int l, int r, Segtree& st) {

}

void solve() {
    int n; cin >> n;
    vi v(n);
    rep(i, n) cin >> v[i];
    Segtree st(v);
    
}

signed main() {
    solve();
}
