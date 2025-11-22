#include <iostream>
#include <vector>
#include <stack>
#include <cstdint>

#define int int64_t
#define rep(i, k) for (int i = 0; i != k; ++i)

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

class MaxStack {
public:
    bool empty() {return data.empty();}
    void push(int x) {
        if (!empty()) {
            int mn = max(x, data.top().second);
            data.push({x, mn});
        } else data.push({x, x});
    }

    int getMax() {return (!data.empty() ? data.top().second : 0);}

    void pop() {if (!empty()) data.pop();}

    int top() {return data.top().first;}

    int size() {return data.size();}

private:
    stack<pair<int, int>> data;
};

signed main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    MaxStack st;
    vi ans;
    rep(i, n) {
        int x; cin >> x;
        if (x == 0) st.pop();
        else st.push(x);
        cout << st.getMax() << '\n';
    }
}