#include <stdio.h>
#include <stdlib.h>

int main() {
    int * m = (int *) malloc (2 * sizeof(int));
    *m = 0;
    *(m + 1) = 1;
    for (int i = 0; i != 2; ++i) printf("%d ", *(m + i));
    printf("\n");
    m = (int *) realloc(m, 4 * sizeof(int));
    *(m + 2) = 2;
    *(m + 3) = 3;
    for (int i = 0; i != 4; ++i) printf("%d ", *(m + i));
    printf("\n");
    free(m);
}