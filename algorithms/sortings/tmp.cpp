#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

template <typename Iter>
Iter choosePivo(Iter start, Iter end) {
    return (start + (rand() % (end - start))); // random choice
    // return end - 1; // Lomuto partition
    // return start; // Hoar partition
}

template <typename Iter>
Iter lomutoPartition(Iter start, Iter end) {
    Iter pivo = choosePivo(start, end);
    std::swap(*pivo, *(end - 1));
    pivo = end - 1;
    Iter movable = start;
    for (Iter it = start; it < end; ++it) {
        if (*it <= *pivo) {
            std::swap(*it, *movable);
            ++movable;
        }
    }
    return movable - 1;
}

template <typename Iter>
Iter hoarPartition(Iter start, Iter end) {
    Iter pivo = choosePivo(start, end);
    Iter left = start, right = end - 1;
    while (true) {
        while (left < end && *left <= *pivo) ++left;
        while (right >= start && *right > *pivo) --right;
        if (left >= right) break;
        std::swap(*left, *right);
    }
    std::swap(*pivo, *right);
    return pivo;
}

template <typename Iter>
void quick_sort(Iter start, Iter end) {
    if (end - start <= 1) return;
    Iter pivo = lomutoPartition(start, end);
    quick_sort(start, pivo);
    quick_sort(pivo + 1, end);
}

int main() {
    std::vector<int> v = {1, 0, 4, 2, 31, 2, 4, 7, 9, -3};
    quick_sort(v.begin(), v.end());
    for (int i = 0; i != v.size(); ++i) {
        std::cout << v[i] << ' ';
    }
}