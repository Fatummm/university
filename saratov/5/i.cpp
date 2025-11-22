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

    int getMax() {return (!data.empty() ? data.top().second : INT32_MIN);}

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
    int n, d; cin >> n >> d;
    vi v(n+1);
    vector<bool> checking(n, false);
    MaxQueue q;
    rep(i, n) {
        cin >> v[i+1];
        if (v[i + 1] == 0) checking[i] = true;
        v[i+1] += v[i];
        q.push(v[i+1]);
    }
    int incremented = 0;
    int cnt = 0;
    rep(i, n) {
        if (q.getMax() + incremented > d) {
            cout << -1 << '\n';
            return 0;
        }
        // cout << v[i+1] + incremented << '\n';
        if (checking[i] && (v[i+1] + incremented < 0)) {
            int need = d - q.getMax();
            if (v[i+1] + need + incremented < 0) {
                cout << -1 << '\n';
                return 0;
            } else {
                incremented += need;
                cnt++;
            }
        }
        q.pop();
    }
    cout << cnt << '\n';
}