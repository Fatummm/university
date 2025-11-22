#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    vector<int> ans(N, -1);
    vector<int> st[2];

    for (int i = N - 1; i >= 0; --i) {
        int p = i & 1;
        while (!st[p].empty() && h[st[p].back()] <= h[i]) st[p].pop_back();
        if (!st[p].empty()) ans[i] = st[p].back() - i;
        else ans[i] = -1;
        st[p].push_back(i);
    }

    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
