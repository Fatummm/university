#include <stdio.h>
#include <stdlib.h>



int main() {
    int n, val; scanf("%d %d", &n, &val);
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
    printf("Target element: %d\n", val);
    int found = 0;
    for (int i = 0; i != n; ++i) {
        if (arr[i] == val && found == 0) {
            ++found;
            printf("Target is found at: %d", i);
        }
        else if (arr[i] == val) printf(" %d", i);
    }
    if (found == 0) printf("No targets");
}