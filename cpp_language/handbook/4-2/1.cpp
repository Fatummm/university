#include <iostream>
#include <vector>
#include <utility>

template <typename T>
class Table {
private:
    std::vector<std::vector<T>> data;
    size_t rows = 0;
    size_t columns = 0;
public:
    Table(size_t r, size_t c): rows(r), columns(c) {
        data.resize(r);
        for (size_t i = 0; i != r; ++i) {
            data[i].resize(c);
        }
    }

    std::vector<T>& operator [] (size_t i) {
        return data[i];
    }

    const std::vector<T>& operator [] (size_t i) const {
        return data[i];
    }

    std::pair<size_t, size_t> size() const {
        return {rows, columns};
    }

    void resize(size_t changed_rows, size_t changed_columns) {
        data.resize(changed_rows);
        for (size_t i = 0; i != changed_rows; ++i) {
            data[i].resize(changed_columns);
        }
        rows = changed_rows;
        columns = changed_columns;
    }
};

template <typename T>
std::ostream& operator << (std::ostream& out, const Table<T>& t) {
    for (size_t i = 0; i != t.size().first; ++i) {
        if (i != 0) out << '\n';
        for (size_t j = 0; j != t.size().second; ++j) {
            if (j != 0) out << ' ';
            out << t[i][j];
        }
    }
    return out;
}

int main() {
    Table<int> t(2,2);
    t[0][0] = 2; t[0][1] = 3; t[1][0] = 5; t[1][1] = 8;
    std::cout << t << '\n';

    const Table<int> t1(3, 3);
    std::cout << t1 << '\n';
    std::cout << t1.size().first << ' ' << t1.size().second << '\n';
}