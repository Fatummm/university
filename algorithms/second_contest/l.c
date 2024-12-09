#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; scanf("%d", &n);
    int * arr = (int *) malloc (n * sizeof(int));
    for (int i = 0; i != n; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("Initial array:\n");
    for (int i = 0; i != n; ++i) {
        if (i != 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    for (int i = 1; i != n; ++i) {
        for (int j = i; j != 0; --j) {
            if (arr[j] < arr[j - 1]) {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
        printf("Insertion - Element #%d\n", i);
        for (int i = 0; i != n; ++i) {
            if (i != 0) printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}