#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    //int * arr = (int *) malloc((n - 1) * sizeof(int));
    int res = 0;
    for (size_t i = 0; i != n - 1; i++) {
        int x;
        scanf("%d", &x);
        res ^= x;
        res ^= (i + 1);
    }
    res ^= n;
    printf("%d", res);
}