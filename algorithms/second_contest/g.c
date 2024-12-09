#include <stdio.h>
#include <stdlib.h>

int partition(int * start, int * end, int mid) {
    //printf("%d\n", start[mid]);
    int * tmp_arr = (int *) malloc ((end - start) * sizeof(int));
    int index = 0;
    for (int i = 0; i != end - start; ++i) {
        if (start[i] <= start[mid] && i != mid) {
            tmp_arr[index] = start[i];
            index++;
        }
    }
    tmp_arr[index] = start[mid]; index++;
    int res = index-1;
    for (int i = 0; i != end - start; ++i) {
        if (start[i] > start[mid]) {
            tmp_arr[index] = start[i];
            index++;
        }
    }
    for (int i = 0; i != index; ++i) {
        start[i] = tmp_arr[i];
    }
    free(tmp_arr);
    return res;
}

void qqsort(int * start, int * end, int * origin_start, int * origin_end) {
    if (end - start <= 1) return;
    int size = end - start;
    int mid = (size - 1) / 2;
    printf("\nPivot index: %d , pivot element: %d\n", mid + (start - origin_start), start[mid]);
    mid = partition(start, end, mid);
    printf("Array after partition:");
    for (int i = 0; i != origin_end - origin_start; ++i) {
        printf(" %d", origin_start[i]);
    }
    printf("\n");
    qqsort(start, start + mid, origin_start, origin_end);
    qqsort(start + mid + 1, end, origin_start, origin_end);
}

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

    qqsort(arr, arr + n, arr, arr + n);
    free(arr);
}

