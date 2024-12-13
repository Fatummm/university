#include <stdio.h>

int main() {
    int arr[] = {1, 23, 3, 2, 0, 2, 3, 5, 2, 4, 1, 2, 4, 6,}; // 14

    for (int i = 1; i != 14; ++i) {
        for (int j = i; j != 0; --j) {
            if (arr[j] < arr[j - 1]) {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
    for (int i = 0; i != 14; ++i) {
        printf("%d ", arr[i]);
    }
}