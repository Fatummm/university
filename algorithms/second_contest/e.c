#include <stdio.h>
#include <stdlib.h>

void merge_arrays(int * start1, int * end1, int * start2, int * end2, int * out) {
    int size = (end1 - start1) + (end2 - start2);
    int * tmp_arr = (int *) malloc (size * sizeof(int));
    int index = 0;
    int *it1 = start1, *it2 = start2;
    while (it1 != end1 && it2 != end2) {
        if (*it1 > *it2) {
            tmp_arr[index] = *it2; it2++;
        }
        else {
            tmp_arr[index] = *it1; it1++;
        }
        index++;
    }
    while (it1 != end1) {
        tmp_arr[index] = *it1; it1++;
        index++;
    }
    while (it2 != end2) {
        tmp_arr[index] = *it2; it2++;
        index++;
    }
    for (int i = 0; i != index; ++i) {
        out[i] = tmp_arr[i];
    }
    free(tmp_arr);
}

void merge_sort(int * start, int * end) {
    if (end - start == 1) return;
    int mid = (end - start) / 2;// + (end - start) % 2;
    merge_sort(start, start + mid);
    merge_sort(start + mid, end);
    printf("\nLeft part:");
    for (int i = 0; i != mid; ++i) {
        printf(" %d", start[i]);
    }
    printf("\nRight part:");
    for (int i = mid; i != end - start; ++i) {
        printf(" %d", start[i]);
    }

    merge_arrays(start, start + mid, start + mid, end, start);
    printf("\nMerged parts:");
    for (int i = 0; i != end - start; ++i) {
        printf(" %d", start[i]);
    }
    printf("\n");

}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for (int i = 0; i != n; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("Initial array:\n");
    for (int i = 0; i != n; ++i) {
        if (i != 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    merge_sort(arr, arr + n);
}