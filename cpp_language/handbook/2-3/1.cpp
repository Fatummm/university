#include <iostream>


int main() {
    long long x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 || y1 == y2 || (abs(x1 - x2) == abs(y1 - y2))) std::cout << "YES";
    else std::cout << "NO";
}