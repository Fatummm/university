#include <stdio.h>

void swap(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection_sort(int * start, int * end) {
    int range = end - start;
    
}

// selection sort
int main() {
    int arr[] = {1, 4, 6, 2, 4, 6, 0, 22, 4, 10}; // 10
    for (int i = 0; i != 10; ++i) {
        size_t min_index = i;
        for (int j = i + 1; j != 10; ++j) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;
    }
    for (int i = 0; i != 10; ++i) {
        printf("%d ", arr[i]);
    }
}