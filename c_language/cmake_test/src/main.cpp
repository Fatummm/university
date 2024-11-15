#include <iostream>
#include "math_functions.h"

int main() {
    int a = 5, b = 3;
    std::cout << "Sum of " << a << " and " << b << " is " << add(a, b) << "\n";
    std::cout << "Difference of " << a << " and " << b << " is " << subtract(a, b) << "\n";
    return 0;
}