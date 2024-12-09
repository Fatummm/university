#include <stdio.h>
#include <stdlib.h>



int main() {
    int n; scanf("%d", &n);
    int mnogo_piva[n];
    for (int i = 0; i != n; ++i) {
        scanf("%d", &mnogo_piva[n - 1 - i]);
    }
    int results[100000];
    int size = 0;
    for (int i = 0; i != n; ++i) {
        size++;
        if (mnogo_piva[i] == -1) results[size - 1] = i + 1;
        else if (mnogo_piva[i] == 0) {
            int mid = (size - 1) / 2;
            for (int j = size - 1; j != mid; --j) {
                results[j] = results[j - 1];
            }
            results[mid] = i + 1;
        }
        else {
            for (int j = size - 1; j != 0; --j) {
                results[j] = results[j - 1];
            }
            results[0] = i + 1;
        }
    }
    for (int i = 0; i != n; ++i) {
        if (i != 0) printf(" ");
        printf("%d", results[i]);
    }
}