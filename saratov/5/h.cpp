#include <iostream>
#include <vector>
#include <cstdint>
#include <set>
#include <stack>
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

    int getMax() {return (!data.empty() ? data.top().second : -1);}

    void pop() {if (!empty()) data.pop();}

    int top() {return data.top().first;}

    int size() {return data.size();}

private:
    stack<pair<int, int>> data;
};

class MaxQueue {
public:
    bool empty() {return head.empty() && tail.empty();}
    int size() {return head.size() + tail.size();}
    void push(int x) {tail.push(x);}

    int getMax() {
        fix();
        return max(head.getMax(), tail.getMax());
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
    MaxStack head, tail;

    void fix() {
        if (head.empty()) {
            while (!tail.empty()) {
                head.push(tail.top());
                tail.pop();
            }
        }
    }
};

signed main() {
    int n, k, x; cin >> n >> k >> x;
    vi v(n);
    rep(i, n) cin >> v[i];
    if (n / k > x) {
        cout << -1 << '\n';
        return 0;
    }
    vvi dp(x + 1, vi(n + 1, -1));
    dp[0][0] = 0;
    for (int i = 1; i != x + 1; ++i) {
        MaxQueue mq;
        mq.push(dp[i-1][0]);
        for (int j = 1; j != n + 1; ++j) {
            dp[i][j] = (mq.getMax() != -1 ? mq.getMax() + v[j-1] : -1);
            mq.push(dp[i - 1][j]);
            if (mq.size() > k) mq.pop();
        }
    }
    int mx = 0;
    for (int i = 0; i < k; ++i) {
        mx = max(mx, dp[x][n - i]);
    }
    cout << mx << '\n';
    // rep(i, dp.size()) {
    //     rep(j, dp[i].size()) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }   
}