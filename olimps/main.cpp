#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> v(10, 5);
    for (int i = 0; i != v.size(); ++i) {
        cout << v[i] << ' ';
    }
}
