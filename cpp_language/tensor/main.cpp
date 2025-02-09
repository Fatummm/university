#include <iostream>
#include <vector>
#include <clocale>
#include <cassert>
#include <functional>


template <class T>
std::vector<std::vector<T>> CreateMatrix(size_t m, size_t n, T val = -1) {
    srand(time(NULL));
    if (val != -1) {return std::vector<std::vector<T>>(m, std::vector<T>(n, val));}
    std::vector<std::vector<T>> v(m, std::vector<T>(n));
    for (size_t i = 0; i != m; ++i) {
        for (size_t j = 0; j != n; ++j) {
            v.at(i).at(j) = rand() % 10;
        }
    }
    return v;
}

template <class T>
void PrintMatrix(const std::vector<std::vector<T>>& v) {
    for (size_t i = 0; i != v.size(); ++i) {
        for (size_t j = 0; j != v.at(i).size(); ++j) {
            if (j != 0) std::cout << ' ';
            std::cout << v.at(i).at(j);
        }
        std::cout << '\n';
    }
}

template <class T>
std::vector<std::vector<T>> AddMatrices(std::vector<std::vector<T>>& a, std::vector<std::vector<T>>& b) {
    std::vector<std::vector<T>> c(a.size());
    for (size_t i = 0; i != c.size(); ++i) {
        c.at(i).resize(a.at(i).size());
        for (size_t j = 0; j != c.at(i).size(); ++j) {
            c.at(i).at(j) = a.at(i).at(j) + b.at(i).at(j);
        }    
    }
    return c;
}

template <class T>
std::vector<std::vector<T>> MultiplyMatrices(std::vector<std::vector<T>>& a, std::vector<std::vector<T>>& b) {
    std::vector<std::vector<T>> c(a.size());
    for (size_t i = 0; i != c.size(); ++i) {
        c.at(i).resize(a.at(i).size());
        for (size_t j = 0; j != c.at(i).size(); ++j) {
            c.at(i).at(j) = a.at(i).at(j) * b.at(i).at(j);
        }    
    }
    return c;
}

template <class T>
std::vector<std::vector<T>> TransposeMatrix(std::vector<std::vector<T>>& a) {
    std::vector<std::vector<T>> v(a.at(0).size(), std::vector<T>(a.size()));
    for (size_t i = 0; i != a.size(); ++i) {
        for (size_t j = 0; j != a.at(i).size(); ++j) {
            v.at(j).at(i) = a.at(i).at(j);
        }
    }
    return v;
}

template <typename T, typename Func>
void ApplyFunction(std::vector<std::vector<T>>& m, Func f) {
    for (size_t i = 0; i != m.size(); ++i) {
        for (size_t j = 0; j != m.at(i).size(); ++j) {
            m.at(i).at(j) = f(m.at(i).at(j));
        }
    }
}

template <typename T, typename Func>
void NewApplyFunction(std::vector<std::vector<T>>& m, Func f) {
    for (size_t i = 0; i != m.size(); ++i) {
        for (size_t j = 0; j != m.at(i).size(); ++j) {
            m.at(i).at(j) = f(m.at(i).at(j));
        }
    }
}

// ===== Тестирование функций =====
void RunTests() {
    // Тест 1: Создание матрицы
    auto A = CreateMatrix(3, 3, 1);
    assert(A[0][0] == 1 && A[2][2] == 1);

    // Тест 2: Сложение
    auto B = CreateMatrix(3, 3, 2);
    auto C = AddMatrices(A, B);
    assert(C[0][0] == 3 && C[2][2] == 3);

    // Тест 3: Умножение
    auto D = MultiplyMatrices(A, B);
    assert(D[0][0] == 2 && D[2][2] == 2);

    // Тест 4: Транспонирование
    auto E = CreateMatrix(2, 3, 5);
    auto F = TransposeMatrix(E);
    assert(F.size() == 3 && F[0].size() == 2);

    // Тест 5: Применение функции (возведение в квадрат)
    ApplyFunction(C, [](int x) { return x * x; });
    assert(C[0][0] == 9 && C[2][2] == 9);

    std::cout << "✔️ Все тесты пройдены!\n";
}

// ===== Основная программа =====
int main() {
    RunTests();

    // Демонстрация работы
    auto mat1 = CreateMatrix(2, 3, 2);
    auto mat2 = CreateMatrix(2, 3, 3);
    
    std::cout << "Матрица 1:\n";
    PrintMatrix(mat1);
    
    std::cout << "Матрица 2:\n";
    PrintMatrix(mat2);
    
    auto sum = AddMatrices(mat1, mat2);
    std::cout << "Сумма матриц:\n";
    PrintMatrix(sum);
    
    auto transposed = TransposeMatrix(sum);
    std::cout << "Транспонированная сумма:\n";
    PrintMatrix(transposed);

    return 0;
}

