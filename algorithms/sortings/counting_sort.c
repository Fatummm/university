#include <stdio.h>

#define RANGE 100

void counting_sort(int * start, int * end) {
    int digits[RANGE] = {0};
    for (int * iter = start; iter != end; ++iter) {
        digits[*iter]++;
    }
    int index = 0;
    for (int * iter = start; iter != end; ++iter) {
        while (digits[index] == 0) index++;
        *iter = index;
        digits[index]--;
    }
}

int main() {
    int arr[] = {1, 2, 5, 2, 0, 4, 2, 6, 2};
    counting_sort(arr, arr + 9);
    for (int i = 0; i != 9; ++i) {
        printf("%d ", arr[i]);
    }
}