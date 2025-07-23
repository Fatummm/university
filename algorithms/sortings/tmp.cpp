#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
template <typename T>
void merge_arrays(typename std::vector<T>::iterator start1, 
    typename std::vector<T>::iterator end1, typename std::vector<T>::iterator start2, typename 
    std::vector<T>::iterator end2, typename std::vector<T>::iterator out) {
    std::vector<T> tmp;
    while (start1 != end1 && start2 != end2) {
        if (*start1 > *start2) {
            tmp.push_back(*start2);
            ++start2;
        }
        else {
            tmp.push_back(*start1);
            ++start1;
        }
    }
    while (start1 != end1) {
        tmp.push_back(*start1);
        ++start1;
    }

    while (start2 != end2) {
        tmp.push_back(*start2);
        ++start2;
    }

    for (typename std::vector<T>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
        *out = *it;
        ++out;
    }
}


template <typename T>
void merge_sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
    if (end - start >= 2) {
        int mid = (end - start) / 2;
        merge_sort<T>(start, start + mid);
        merge_sort<T>(start + mid, end);
        merge_arrays<T>(start, start + mid, start + mid, end, start);
    }
}

int main() {
    std::vector<int> v = {1, 0, 4, 2, 31, 2, 4, 7, 9, -3};
    merge_sort<int>(v.begin(), v.end());
    for (int i = 0; i != v.size(); ++i) {
        std::cout << v[i] << ' ';
    }
}