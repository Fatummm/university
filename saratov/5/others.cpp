#include <bits/stdc++.h>

#define int int64_t
#define rep(i, k) for (int i = 0; i != k; ++i)

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

class MinStack {
public:
    bool empty() {return data.empty();}
    void push(int x) {
        if (!empty()) {
            int mn = min(x, data.top().second);
            data.push({x, mn});
        } else data.push({x, x});
    }
    int getMin() {return data.top().second;}
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
        return head.getMin();
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

signed main() {
    
}