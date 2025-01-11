#include <iostream>

bool checkVisokosniy(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int main() {
    int month, year;
    std::cin >> month >> year;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
            std::cout << 31;
            break;
        }
        case 4: case 6: case 9: case 11: {
            std::cout << 30;
            break;
        }
        default: {
            std::cout << ((checkVisokosniy(year)) ? 29 : 28);
        }
    }
}