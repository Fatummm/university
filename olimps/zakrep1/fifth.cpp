#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <deque>
#include <algorithm>
#define ll long long
using namespace std;


template <typename T>
std::istream& operator >> (std::istream& in, std::vector<T>& v) {
    if (v.size() == 0) {
        T temp;
        while (in >> temp) {
            v.push_back(temp);
        }
    }
    else {
        for (size_t i = 0; i != v.size(); ++i) {
            in >> v[i];
        }
    }
    return in;
}

template <typename T>
std::ostream& operator << (std::ostream& out, std::vector<T>& v) {
    for (size_t i = 0; i != v.size(); ++i) {
        if (i != 0) {
            out << ' '; // вывод разделителя, можно заменить на '\n'
        }               // или любой другой нужный
        out << v[i];
    }
    return out;
}



int main() {
    ll n; cin >> n;
    vector<ll> v(n); cin >> v;
    sort(v.begin(), v.end());
    //cout << v << '\n';
    ll counter = 0;
    for (ll i = 0, j = 0; j != n; ) {
        if (v[i] * 2 <= v[j]) {
            ++counter;
            ++i;
        }
        ++j;
    }
    cout << n - counter << '\n';
}
// 1 2 4 8