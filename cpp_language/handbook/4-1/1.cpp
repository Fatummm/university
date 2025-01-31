#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;
    bool IsLeapYear();
    int GetDaysInMonth();
    void Normalize();
public:
    Date(): day(1), month(1), year(1970) {}
    Date(int d, int m, int y): day(d), month(m), year(y) {
        Normalize();
    }
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;

    void Print() const;

    void ChangeYear(int);
    void ChangeMonth(int);

    Date operator + (int);
    Date operator - (int);
    int operator - (Date&);

};

void Date::Print() const {
        if (day < 10) std::cout << '0';
        std::cout << day << '.';
        if (month < 10) std::cout << '0';
        std::cout << month << '.' << year << std::endl;
    }

void Date::ChangeYear(int val) {
        year += val;
    }

void Date::ChangeMonth(int val) {
        if (val == -1 && month == 1) {
            year--;
            month = 12;
        }
        else if (val == 1 && month == 12) {
            year++;
            month = 1;
        }
        else month += val;
    }

bool Date::IsLeapYear() {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

int Date::GetDaysInMonth() {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
            return 31; break;
        }
        case 4: case 6: case 9: case 11: {
            return 30; break;
        }
        default: {
            return 28 + IsLeapYear();
        }
    }
}

void Date::Normalize() {
    while (day > GetDaysInMonth()) {
        day -= GetDaysInMonth();
        ChangeMonth(1);
    }
    while (day < 1) {
        ChangeMonth(-1);
        day += GetDaysInMonth();
    }
}

int Date::GetDay() const {
    return day;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetYear() const {
    return year;
}

Date Date::operator + (int days) {
        return Date(day + days, month, year);
    }

Date Date::operator - (int days) {
    return Date(day - days, month, year);
}

int Date::operator - (Date& other) {
    while (month != other.month || year != other.year) {
        if (year > other.year) {
            day = day + 365 + IsLeapYear();
            ChangeYear(-1);
        }
        else if (other.year > year) {
            other.day = other.day + 365 + other.IsLeapYear();
            other.ChangeYear(-1);
        }
        else if (month > other.month) {
            ChangeMonth(-1);
            day += GetDaysInMonth();
        }
        else {
            other.ChangeMonth(-1);
            other.day += other.GetDaysInMonth();
        }
    }
    return day - other.day;
}

int main() {
    Date d1(1, 1, 2025);
    Date d2 = d1 + 10000;
    int x = d2 - d1;
    d1.Print();
    std::cout << x << std::endl;
}