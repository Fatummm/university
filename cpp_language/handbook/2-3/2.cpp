#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a*a + b*b == c*c || b*b + c*c == a*a || c*c + a*a == b*b) std::cout << "YES";
    else if (a + b > c && b + c > a && c + a > b) std::cout << "NO";
    else std::cout << "UNDEFINED";
}