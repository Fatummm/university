#include <iostream>
#include <vector>

template <typename T>
class Polynomial {
private:
    std::vector<T> data;
    using constIter = typename std::vector<T>::const_iterator;
    
public:
    inline static T zero{0};
    void Normalize() {
        while (!data.empty() && data.back() == zero) data.pop_back();
    }
    // 1

    Polynomial() = default;
    Polynomial(const std::vector<T> v): data{v} {Normalize();}

    Polynomial(T value) {
        data.push_back(value);
        Normalize();
    }

    template <typename Iter>
    Polynomial(Iter first, Iter last): data{first, last} {
        Normalize();
    }

    // 4
    const T& operator [] (int i) const {
        if (static_cast<size_t>(i) >= data.size()) return zero;
        return data[i];
    }

    T& operator [] (int i) {
        if (static_cast<size_t>(i) >= data.size()) return zero;
        return data[i];
    }

    int Degree () const {
        return int(data.size()) - 1;
    }

    // 2
    bool operator == (const Polynomial& other) const {
        return data == other.data;
    }

    bool operator != (const Polynomial& other) const {
        return !operator==(other);
    }

    bool operator == (const T& scalar) {
        return data.size() == 1 && data[0] == scalar;
    }

    bool operator != (const T& scalar) {
        return !operator==(scalar);
    }

    std::vector<T>& GetData() {
        return data;
    }
    const std::vector<T>& GetData() const {
        return data;
    }

    constIter begin() const {
        return data.cbegin();
    }
    
    constIter end() const {
        return data.cend();
    }

    T operator()(const T& x) const {
        T result = T(0);
        for (int i = static_cast<int>(data.size()) - 1; i >= 0; --i) {
            result = result * x + data[i];
        }
        return result;
    }
};

template <typename T>
std::ostream& operator << (std::ostream& out, const Polynomial<T>& p) {
    for (int i = p.Degree(); i >= 0; --i) {
        if (i != p.Degree()) out << ' ';
        out << p[i];
    }
    return out;
} 
template <typename T>
bool operator == (const T& scalar, const Polynomial<T>& pol) {
    return pol == scalar;
}

template <typename T>
bool operator != (const T& scalar, const Polynomial<T>& pol) {
    return pol != scalar;
}

template <typename T>
Polynomial<T>& operator += (Polynomial<T>& first, const Polynomial<T>& second) {
    for (int i = 0; i <= second.Degree(); ++i) {
        if (first.Degree() < i) first.GetData().push_back(second[i]);
        else first[i] += second[i];
    }
    first.Normalize();
    return first;
}

template <typename T>
Polynomial<T> operator + (Polynomial<T> first, const Polynomial<T>& second) {
    return first += second;
}

template <typename T>
Polynomial<T>& operator += (Polynomial<T>& first, const T& second) {
    if (first.Degree() == -1) first.GetData().push_back(second);
    else first[0] += second;
    first.Normalize();
    return first;
}

template <typename T>
Polynomial<T> operator + (Polynomial<T> first, const T& second) {
    return first += second;
}

template <typename T>
Polynomial<T>& operator -= (Polynomial<T>& first, const Polynomial<T>& second) {
    for (int i = 0; i <= second.Degree(); ++i) {
        if (first.Degree() < i) first.GetData().push_back(-second[i]);
        else first[i] -= second[i];
    }
    first.Normalize();
    return first;
}

template <typename T>
Polynomial<T> operator - (Polynomial<T> first, const Polynomial<T>& second) {
    return first -= second;
}

template <typename T>
Polynomial<T>& operator -= (Polynomial<T>& first, const T& second) {
    if (first.Degree() == -1) first.GetData().push_back(second);
    else first[0] -= second;
    first.Normalize();
    return first;
}

template <typename T>
Polynomial<T> operator - (Polynomial<T> first, const T& second) {
    return first -= second;
}

template <typename T>
Polynomial<T>& operator *= (Polynomial<T>& first, const Polynomial<T>& second) {
    Polynomial<T> tmp(Polynomial<T>::zero); tmp.GetData().resize(first.Degree() + second.Degree() + 1);
    for (int i = 0; i <= first.Degree(); ++i) {
        for (int j = 0; j <= second.Degree(); ++j) {
            tmp[i+j] += first[i] * second[j];
        }
    }
    first.GetData() = tmp.GetData();
    first.Normalize();
    return first;
}

template <typename T>
Polynomial<T> operator * (Polynomial<T> first, const Polynomial<T>& second) {
    return first *= second;
}

template <typename T>
Polynomial<T>& operator *= (Polynomial<T>& first, const T& second) {
    for (int i = 0; i <= first.Degree(); ++i) {
        first[i] *= second;
    }
    first.Normalize();
    return first;
}

template <typename T>
Polynomial<T> operator * (Polynomial<T> first, const T& second) {
    return first *= second;
}

// int main() {
//     std::vector<int> v1 = {1, 2, 3, 4, 5};
//     std::vector<int> v2 = {1, 2, 3};
//     Polynomial<int> p1(v2.begin(), v2.end());
//     Polynomial<int> p2(v1.begin(), v1.end());
//     p2 *= 10;
//     std::cout << p1(2) << '\n';
// }
