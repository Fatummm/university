#include <iostream>

class Date {
private:
    int days;
    bool IsLeapYear(int) const;
    int GetDaysInMonth(int) const;
public:
    Date(): days(1){}
    Date(int n): days(n) {if (n < 0) days = 1;}
    Date(int d, int m, int y);

    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;

    void Print() const;

    Date operator + (int);
    Date operator - (int);
    int operator - (Date&);
};

bool Date::IsLeapYear(int x) const {
    return (x % 400 == 0) || (x % 100 != 0 && x % 4 == 0);
}

int Date::GetDaysInMonth(int n) const {
    switch (n) {
        case 2: {
            return 28 + IsLeapYear(GetYear()); break;
        }
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
            return 31;
        }
        default: return 30;
    }
}

Date::Date(int d, int m, int y) {
    while (m != 1) {
        --m;
        d += GetDaysInMonth(m);
    }
    while (y != 1970) {
        --y;
        d += 365 + IsLeapYear(y);
    }
    days = d;
}

int Date::GetDay() const {
    int year = 1970, month = 1, d = days;
    while (d > 365 + IsLeapYear(year)) {
        d -= (365 + IsLeapYear(year));
        ++year;
    }
    while (d > GetDaysInMonth(month)) {
        d -= GetDaysInMonth(month);
        month = (month) % 12 + 1;
    }
    return d;
}

int Date::GetMonth() const {
    int year = 1970, month = 1, d = days;
    while (d > 365 + IsLeapYear(year)) {
        d -= (365 + IsLeapYear(year));
        ++year;
    }
    while (d > GetDaysInMonth(month)) {
        d -= GetDaysInMonth(month);
        month = (month) % 12 + 1;
    }
    return month;
}

int Date::GetYear() const {
    int year = 1970, month = 1, d = days;
    while (d > 365 + IsLeapYear(year)) {
        d -= (365 + IsLeapYear(year));
        ++year;
    }
    return year;
}

void Date::Print() const {
    if (GetDay() < 10) std::cout << '0';
    std::cout << GetDay() << '.';
    if (GetMonth() < 10) std::cout << '0';
    std::cout << GetMonth() << '.';
    std::cout << GetYear() << std::endl;
}

// Date operator + (int);
// Date operator - (int);
// int operator - (Date&);

Date Date::operator + (int n) {
    return Date(days + n);
}

Date Date::operator - (int n) {
    return Date(days - n);
}

int Date::operator - (Date& other) {
    return days - other.days;
}

int main() {
    Date d1(1, 1, 2020);
    d1 = d1 - 100;
    Date d2(1001);
    //std::cout << d2 - d1 << std::endl;
    d1.Print();
}