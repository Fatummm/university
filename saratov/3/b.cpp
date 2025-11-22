#include <iostream>
#include <vector>
#include <string>

using namespace std;

signed main() {
    string s; cin >> s;
    char last = '-';
    int underlined = 0;
    bool last_underlined = false;
    for (int i = 0; i != s.size(); ++i) {
        if (s[i] == 'w') {
            underlined++;
        }
        if (s[i] == 'v' && !last_underlined && last == 'v') {
            underlined++;
            last_underlined = true;
        }
        else last_underlined = false;
        last = s[i];
    }
    cout << underlined << '\n';
}
