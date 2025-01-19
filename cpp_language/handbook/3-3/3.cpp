#include <iostream>
#include <vector>

template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1,
                      InIter2 first2, InIter2 last2,
                      OutIter out) {
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) {
            *out = *first1; ++first1; ++out;
        }
        else if (*first1 > *first2) {
            ++first2;
        }
        else if (*first1 == *first2) {
            ++first1; ++first2;
        }
    }
    while (first1 != last1) {
        *out = *first1; ++first1; ++out;
    }
    return out;
}


int main() {
    std::vector<int> v1 = {1, 1, 2, 3, 4, 5, 5, 5, 6};
    std::vector<int> v2 = {1, 2, 2, 4, 5, 5};
    std::vector<int> v3(10);
    SetDifference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for (int i = 0; i != 10; ++i) {
        std::cout << v3.at(i) << ' ';
    }
}