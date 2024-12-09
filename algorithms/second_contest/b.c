#include <stdio.h>
#include <stdlib.h>


int main() {
    int n; scanf("%d", &n);
    int val; scanf("%d", &val);
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
    printf("Search history: ");
    int r = n - 1, l = 0, mid = 0;
    int ans = -1;
    while (r >= l) {
        mid = (r + l) / 2;
        printf("%d(%d) ", arr[mid], mid);
        if (arr[mid] > val) r = mid - 1;
        else if (arr[mid] < val) l = mid + 1;
        else {
            ans = mid; break;
        }
    }
    printf("\n");
    if (ans != -1) printf("Target is found at: %d", ans);
    else printf("No targets");

    free(arr);
}