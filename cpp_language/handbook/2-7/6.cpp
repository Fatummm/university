#include <iostream>
#include <vector>
#include <algorithm>

#define SEPARATOR '\n'

struct Point {
    int x, y;
    char sep;
} point_t;

std::istream& operator >> (std::istream& in, Point& p) {
    in >> p.x >> p.y;
    p.sep = ' ';
    return in;
}

std::ostream& operator << (std::ostream& out, const Point& p) {
    out << p.x << p.sep << p.y;
    return out;
}

template <typename T>
std::istream& operator >> (std::istream& in, std::vector<T>& v) {
    for (size_t i = 0; i != v.size(); ++i) {
        in >> v[i];
    }
    return in;
}

template <typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& v) {
    for (size_t i = 0; i != v.size(); ++i) {
        out << v[i] << SEPARATOR;
    }
    return out;
}

bool operator < (const Point& lhs, const Point& rhs) {
    return lhs.x * lhs.x + lhs.y * lhs.y < rhs.x * rhs.x + rhs.y * rhs.y;
}

int main() {
    size_t n; std::cin >> n;
    std::vector<Point> v(n); std::cin >> v;
    std::sort(v.begin(), v.end());
    std::cout << v;
} // (0, 0), (3, 4), (1, -1), (-2, 2), (5, 5), (-3, 0), (10, -10), (6, -2), (9, 1), (7, -7)