#include <stdio.h>
#include <stdlib.h>


int main() {
    int n; scanf("%d", &n);
    //int * arr = (int *) malloc (n * sizeof(int));
    long long arr[100000];
    for (int i = 0; i != n; ++i) {
        scanf("%ld", &arr[i]);
        //arr[i] = rand() % 500;
    }
    for (int i = 0; i != n; ++i) {
        if (i == 0) printf("Step 0:\n");
        if (i != 0) printf(" ");
        printf("%ld", arr[i]);
    }
    printf("\n");
    
    for (int x = 1; x <= n / 2 - 1; ++x) {
        // sorting of first part
        for (int j = x; j != 0; --j) {
            if (arr[j] < arr[j - 1]) {
                long long tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }

        // sorting of second part
        for (int j = n - x - 1; j != n - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                long long tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        printf("Step %ld:\n", x);
        for (int i = 0; i != n; ++i) {
            if (i != 0) printf(" ");
            printf("%ld", arr[i]);
        }
        printf("\n");
    }
}