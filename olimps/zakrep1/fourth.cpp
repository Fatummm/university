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
    ll n, d; cin >> n >> d;
    vector<ll> v(n); cin >> v;
    ll counter = 0;
    for (int i = 0; i != n; ++i) {
        auto index = lower_bound(v.begin(), v.end(), v[i] + d);
        if (index == v.end() || *index > v[i] + d) --index;
        ll k = (index - v.begin()) - i;
        //cout << k << ' ';
        if (k <= 0) continue;
        counter += k * (k - 1) / 2;
    }
    cout << counter;
}