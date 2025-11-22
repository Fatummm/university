#include <iostream>

using std::cin, std::cout;

const int N = 100;

const int inf = 1e9;

int main(){
    int a[N];
    int n; cin >> n;
    if (n == 1) {
        cout << -1 << '\n';
        return 0;
    }
    int index = 0;
    for (int i = 0; i != n; ++i) {
        cin >> a[i];
        if (a[i] > a[index]) {
            index = i;
        }
    }
    a[index] = -inf;

    index = 0;
    
    for (int i = 0; i != n; ++i) {
        if (a[i] > a[index]) {
            index = i;
        }
    }

    cout << a[index] << '\n';

}
