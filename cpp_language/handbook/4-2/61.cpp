
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <initializer_list>

template<typename T>
class Polynomial {
private:
    std::vector<T> data;

    void Normalize() {
        while (!data.empty() && data.back() == T(0)) data.pop_back();
    }

public:
    using const_iter = typename std::vector<T>::const_iterator;
    
    Polynomial(const std::vector<T>& c) : data(c) {
        Normalize();
    }

    
    Polynomial(const T& value = T()) : data{value} {
        Normalize();
    }

    
    template<typename Iter>
    Polynomial(Iter begin, Iter end) : data(begin, end) {
        Normalize();
    }

    
    bool operator==(const Polynomial<T>& other) const {
        return data == other.data;
    }

    bool operator!=(const Polynomial<T>& other) const {
        return !(*this == other);
    }

    bool operator==(const T& value) const {
        return *this == Polynomial<T>(value);
    }

    bool operator!=(const T& value) const {
        return !(*this == value);
    }

    Polynomial<T>& operator+=(const Polynomial<T>& rhs) {
        if (rhs.data.size() > data.size()) {
            data.resize(rhs.data.size(), T(0));
        }
        for (size_t i = 0; i < rhs.data.size(); ++i) {
            data[i] += rhs.data[i];
        }
        Normalize();
        return *this;
    }

    Polynomial<T>& operator+=(const T& value) {
        if (data.empty()) data.push_back(T(0));
        data[0] += value;
        Normalize();
        return *this;
    }
    
    Polynomial<T> operator+(const Polynomial<T>& rhs) const {
        Polynomial<T> result = *this;
        result += rhs;
        return result;
    }

    Polynomial<T> operator+(const T& value) const {
        Polynomial<T> result = *this;
        result += value;
        return result;
    }

    Polynomial<T>& operator-=(const Polynomial<T>& rhs) {
        if (rhs.data.size() > data.size()) {
            data.resize(rhs.data.size(), T(0));
        }
        for (size_t i = 0; i < rhs.data.size(); ++i) {
            data[i] -= rhs.data[i];
        }
        Normalize();
        return *this;
    }

    Polynomial<T>& operator-=(const T& value) {
        if (data.empty()) data.push_back(T(0));
        data[0] -= value;
        Normalize();
        return *this;
    }

    Polynomial<T> operator-(const Polynomial<T>& rhs) const {
        Polynomial<T> result = *this;
        result -= rhs;
        return result;
    }

    Polynomial<T> operator-(const T& value) const {
        Polynomial<T> result = *this;
        result -= value;
        return result;
    }

    Polynomial<T>& operator*=(const Polynomial<T>& rhs) {
        *this = *this * rhs;
        return *this;
    }

    Polynomial<T>& operator*=(const T& value) {
        for (T& c : data) {
            c *= value;
        }
        Normalize();
        return *this;
    }
    
    Polynomial<T> operator*(const Polynomial<T>& rhs) const {
        std::vector<T> res(data.size() + rhs.data.size() - 1, T(0));
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < rhs.data.size(); ++j) {
                res[i + j] += data[i] * rhs.data[j];
            }
        }
        return Polynomial<T>(res);
    }

    Polynomial<T> operator*(const T& value) const {
        Polynomial<T> result = *this;
        result *= value;
        return result;
    }

    const T operator[](size_t degree) const {
        if (degree < data.size()) return data[degree];
        return T(0);
    }

    int Degree() const {
        return static_cast<int>(data.size()) - 1;
    }

    T operator()(const T& x) const {
        T result = T(0);
        for (int i = static_cast<int>(data.size()) - 1; i >= 0; --i) {
            result = result * x + data[i];
        }
        return result;
    }

    const_iter begin() const {
        return data.cbegin();
    }

    const_iter end() const {
        return data.cend();
    }

    friend std::ostream& operator<<(std::ostream& out, const Polynomial<T>& p) {
        for (int i = p.Degree(); i >= 0; --i) {
            if (i != p.Degree()) out << ' ';
            out << p[i];
        }
        return out;
    }
};

