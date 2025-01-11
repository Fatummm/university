#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <deque>
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
    map<ll, ll> mp;
    vector<ll> pows;
    for (int i = 1; i != 40; ++i) {
        pows.push_back(pow(2, i));
    }
    for (ll i = 0; i != n; ++i) {
        
        ++mp[v[i]];
    }
    ll counter = 0;
    for (ll i = 0; i != n; ++i) {
        for (ll j = 0; j != pows.size(); ++j) {
            if (pows[j] - v[i] > 0) {
                if (pows[j] - v[i] == v[i]) counter += mp[v[i]] - 1;
                else counter += mp[pows[j] - v[i]];
            }
        }
        --mp[v[i]];
    }
    cout << counter;
}