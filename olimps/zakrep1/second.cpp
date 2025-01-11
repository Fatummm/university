#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
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

struct Person {
    int w, h;
};

int main() {
    int n; cin >> n;
    vector<Person> v(n);
    map<int, int> heights;
    int width = 0;
    for (int i = 0; i != n; ++i) {
        cin >> v[i].w >> v[i].h;
        width += v[i].w;
        if (heights[v[i].h]) heights[v[i].h]++;
        else heights[v[i].h] = 1;
    }
    for (int i = 0; i != n; ++i) {
        int height = 0;
        for (auto it = heights.rbegin(); it != heights.rend(); ++it) {
            if (it->first == v[i].h && it->second == 1) continue;
            else height = it->first;
            break;
        }
        cout << height * (width - v[i].w) << ' ';
    }
    

}