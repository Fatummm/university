#include <vector>
#include <string>
#include <iostream>
#include <cstdint>

using namespace std;

#define int int64_t


signed main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> v(26, vector<int>(1, 0));
    for (int i = 0; i != n; ++i) {
        v[s[i]-'a'].push_back(i);
    }
    int m; cin >> m;
    vector<int> ans;
    for (int i = 0; i != m; ++i) {
        string ss; cin >> ss;
        vector<int> vv(26, 0);
        for (char& elem : ss) {
            vv[elem - 'a']++;
        }
        int mx = 0;
        for (int i = 0; i != vv.size(); ++i) {
            mx = max(mx, v[i][vv[i]] + 1);
        }
        ans.push_back(mx);
    }

    for (int i = 0; i != ans.size(); ++i) {
        cout << ans[i] << '\n';
    }
}