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
    auto iter = lower_bound(v.begin(), v.end(), v[0] * 2);
    if (iter == v.end()) {
        cout << n;
        return 0;
    }
    ll count = 0;
    ll index2 = (n % 2 == 0) ? n / 2 : (v[n/2] * 2 < v[v.size() - 1]) ? n / 2 : n/2 - 1, index1 = 0;
    while (index2 != v.size()) {
        if (v[index1] * 2 <= v[index2]) {
            count++;
            index1++;
            index2++;
        }
        else ++index2;
    }
    cout << n - count;
}