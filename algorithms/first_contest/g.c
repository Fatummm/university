#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n; scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i != n; ++i) {
        scanf("%d", &arr[i]);
    }
    int m; scanf("%d", &m);
    for (int x = 0; x != m; ++x) {
        int q; scanf("%d", &q);
        if (q == 0) {
            int ind, val; scanf("%d %d", &ind, &val);
            ind--;
            n++;
            for (int i = n - 1; i != ind; --i) {
                arr[i] = arr[i-1];
            }
            arr[ind] = val;
            for (int i = 0; i != n; ++i) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else {
            int ind; scanf("%d", &ind); ind--;
            n--;
            for (int i = ind; i != n; ++i) {
                arr[i] = arr[i + 1];
            }
            for (int i = 0; i != n; ++i) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
}