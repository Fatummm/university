#include <iostream>

void printDay(int day) {
    if (day == 0) std::cout << "  ";
    else if (day < 10) std::cout << ' ' << day;
    else std::cout << day;
}

int main() {
    int day, number; std::cin >> day >> number;
    int current_day = 1;
    int days = 1;
    while (day != current_day) {
        if (current_day != 1) std::cout << ' ';
        printDay(0);
        current_day++;
    }
    if (day != 1) std::cout << ' ';
    printDay(days); std::cout << ' ';
    days++;
    while (days <= number) {
        if (current_day == 7) {
            std::cout << '\n';
            current_day = 0;
        }
        printDay(days); std::cout << ' ';
        days++;
        current_day++;
    }
}