#include <stdio.h>
#include <stdlib.h>

void merge_arrays(int * start1, int * end1, int * start2, int * end2, int * out) {
    int * it1 = start1;
    int * it2 = start2;
    int * temp_out = (int*)malloc(((end1 - start1) + (end2 - start2)) * sizeof(int));
    int ind = 0;
    while (it1 != end1 && it2 != end2) {
        if (*it1 > *it2) {
            temp_out[ind] = *it2;
            it2++;
            ind++;
        }
        else {
            temp_out[ind] = *it1;
            it1++;
            ind++;
        }
    }
    
    while (it1 != end1) {
        temp_out[ind] = *it1;
        it1++;
        ind++;
    }

    while (it2 != end2) {
        temp_out[ind] = *it2;
        it2++;
        ind++;
    }
    for (int i = 0; i != ind; ++i) {
        *(out + i) = temp_out[i];
    }
    free(temp_out);
}

void merge_sort(int * start, int * end) {
    if (end - start >= 2) {
        int mid = (end - start) / 2;
        merge_sort(start, start + mid);
        merge_sort(start + mid, end);
        merge_arrays(start, start + mid, start + mid, end, start);
    }
}

int main() {
    int arr[] = {1, 24, 6, 2, 4, 8, 9, 9, 3, 44, 2, 6, 1, 0};
    merge_sort(arr, arr + 14);
    for (int i = 0; i!= 14; ++i) {
        printf("%d ", arr[i]);
    }

}