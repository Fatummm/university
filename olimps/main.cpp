#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <stdio.h>
using namespace std;

#define ll long long


template <typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    for (size_t i = 0; i != v.size(); ++i) {
        if (i != 0) out << ' ';
        out << v[i];
    }
    return out;
}

template <typename T>
istream& operator >> (istream& in, const vector<T>& v) {
    for (size_t i = 0; i != v.size(); ++i) {
        in >> v[i];
    }
    return in;
}


bool check(vector<pair<ll, ll>>& v, long double t) {
    long double right = -1e9 - 1, left = 1e9 + 1;
    bool boom = false;
    for (size_t i = 0; i != v.size(); ++i) {
        if (v[i].second > 0) right = max(right, v[i].first + v[i].second * t);
        if (v[i].second < 0 && v[i].first + v[i].second * t < right) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);  
    srand(time(NULL));
    for (int j = 0; j != 5; ++j) {
        for (int i = 0; i != 6; ++i) {
            std::cout << rand() % 1000 << ' ';
        }
        std::cout << '\n';
    }
}