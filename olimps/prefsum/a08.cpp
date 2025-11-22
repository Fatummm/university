#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include <random>
#include <chrono>
#include <stack>

//#define int int64_t
#define rep(i, n) for (int i = 0; i != n; ++ i)

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void iostreamUntie() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

class MinStack {
public:
    bool empty() {return data.empty();}
    void push(int x) {
        if (!empty()) {
            int mn = min(x, data.top().second);
            data.push({x, mn});
        } else data.push({x, x});
    }
    int getMin() {return data.empty() ? INT32_MAX : data.top().second;}
    void pop() {data.pop();}
    int top() {return data.top().first;}
    int size() {return data.size();}
private:
    stack<pair<int, int>> data;
};

class MinQueue {
public:
    bool empty() {return head.empty() && tail.empty();}
    int size() {return head.size() + tail.size();}
    void push(int x) {tail.push(x);}
    int getMin() {
        fix();
        return min(head.getMin(), tail.getMin());
    }

    int front() {
        fix();
        return head.top();
    }

    void pop() {
        fix();
        head.pop();
    }
private:
    MinStack head, tail;

    void fix() {
        if (head.empty()) {
            while (!tail.empty()) {
                head.push(tail.top());
                tail.pop();
            }
        }
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> pref(n, vector<int>(m, 0));
    char c;
    rep(i, n) {
        rep(j, m) {
            cin >> c;
            if (j == 0) pref[i][j] = c - '0';
            else if (c != '0') pref[i][j] = pref[i][j-1] + c - '0';
        }
    }
    int mx = 0;
    for (int len = 1; len <= n; ++len) {
        rep(j, m) {
            MinQueue mq;
            rep(k, len) {
                mq.push(pref[k][j]);
            }
            mx = max(mx, mq.getMin() * len);
            for(int k = len; k != n; ++k) {
                mq.pop();
                mq.push(pref[k][j]);
                mx = max(mx, mq.getMin() * len);
            }
        }
    }
    cout << mx << '\n';
}

signed main() {
    iostreamUntie();
    int t = 1;
    //cin >> t;
    while (t--) solve();
}