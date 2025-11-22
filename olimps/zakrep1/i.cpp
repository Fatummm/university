#include <iostream>
#include <vector>
#include <string>

using namespace std;

signed main() {
    char a, b; int x, y;
    cin >> a >> x >> b >> y;
    vector<string> ans;
    while (a != b && x != y) {
        if (x > y && a > b) {
            ans.push_back("LD");
            --x;
            --a;
        }
        else if (x > y && b > a) {
            ans.push_back("RD");
            --x;
            ++a;
        }
        else if (x < y && a > b) {
            ans.push_back("LU");
            ++x;
            --a;
        }
        else {
            ans.push_back("RU");
            ++x;
            ++a;
        }
    }
    while (a != b || x != y) {
        if (x > y) {
            ans.push_back("D");
            --x;
        }
        else if (x < y) {
            ans.push_back("U");
            ++x;
        }
        else if (a > b) {
            ans.push_back("L");
            --a;
        }
        else {
            ans.push_back("R");
            ++a;
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i != ans.size(); ++i) {
        cout << ans[i] << '\n';
    }
}
