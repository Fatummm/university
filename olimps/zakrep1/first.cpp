#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <deque>
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
    int n; cin >> n;
    deque<int> v(n);
    for (int i = 0; i != n; ++i) {
        cin >> v[i];
    }
    int dima = 0, serezha = 0;
    for (int i = 0; i != n; ++i) {
        if (i % 2 == 0) {
            serezha += max(v.front(), v.back());
            if (v.front() > v.back()) v.pop_front();
            else v.pop_back();
        }
        else {
            dima += max(v.front(), v.back());
            if (v.front() > v.back()) v.pop_front();
            else v.pop_back();
        }
    }
    cout << serezha << ' ' << dima;

}