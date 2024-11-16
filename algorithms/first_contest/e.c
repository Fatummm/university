#include <stdio.h>
#include <stdlib.h>

#define ll long long


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    ll matrix[500][500];
    ll rows[500];
    ll columns[500];
    for (ll i = 0; i < m; ++i) {
        columns[i] = 0;
    }

    for (int i = 0; i != n; ++i) {
        rows[i] = 0;
        for (int j = 0; j != m; ++j) {
            scanf("%ld", &matrix[i][j]);
            rows[i] += matrix[i][j];
            columns[j] += matrix[i][j];
        }
    }
    for (int i = 0; i != n; ++i) {
        printf("%ld", rows[i]);
        if (i + 1 != n) printf(" ");
    }
    printf("\n");
    for (int i = 0; i != m; ++i) {
        printf("%ld", columns[i]);
        if (i + 1 != m) printf(" ");
    }
}