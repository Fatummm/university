#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int * arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i!= n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i != m; ++i) {
        int ind1, ind2; scanf("%d %d", &ind1, &ind2);
        swap(&arr[ind1], &arr[ind2]);
    }

    for (int i = 0; i != n; ++i) {
        printf("%d ", arr[i]);
    }
    free(arr);
}