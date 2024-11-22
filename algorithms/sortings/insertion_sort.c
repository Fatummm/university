#include <stdio.h>

int main() {
    int arr[] = {1, 23, 3, 2, 0, 2, 3, 5, 2, 4, 1, 2, 4, 6,}; // 14

    for (int i = 0; i != 14; ++i) {
        int index = i;
        for (int j = i - 1; j >= 0; --j) {
            if (arr[index] < arr[j]) {
                int tmp = arr[index];
                arr[index] = arr[j];
                arr[j] = tmp;
                index = j;
            }
        }
    }
    for (int i = 0; i != 14; ++i) {
        printf("%d ", arr[i]);
    }
}