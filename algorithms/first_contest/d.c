#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a > b) ? b : a;
}

int main() {
    int n;
    scanf("%d", &n);
    int * arr1 = (int *) malloc (n * sizeof(int));
    int * arr2 = (int *) malloc (n * sizeof(int));
    int * arr3 = (int *) malloc (n * sizeof(int));
    for (int i = 0; i != n; ++i) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i != n; ++i) {
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i != n; ++i) {
        arr3[i] = min(arr1[i], arr2[i]);
    }
    for (int i = 0; i != n; ++i) {
        printf("%d ", arr3[i]);
    }
    free(arr1); free(arr2); free(arr3);
}