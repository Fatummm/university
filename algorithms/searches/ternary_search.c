#include <stdio.h>

int * ternary_search(int * start, int * end, int value) {
    int l = 0, r = end - start - 1, mid1 = 0, mid2 = 0;
    while (r >= l) {
        mid1 = l + (r - l) / 3;
        mid2 = r - (r - l) / 3;


        if (start[mid1] == value) return start + mid1;
        if (start[mid2] == value) return start + mid2;


        if (start[mid1] > value) r = mid1 - 1;
        else if (start[mid2] < value) l = mid2 + 1;
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
        //printf("%d %d %d %d\n", l, mid1, mid2, r);
    }
    return end;
}

int main() {
    int arr[1000];
    for (int i = 0; i != 1000; ++i) {
        arr[i] = i;
    }
    for (int value = 0; value != 1000; ++value) {
        int * ans = ternary_search(arr, arr + 1000, value);
        if (ans == arr + 1000) {
            printf("Couldn't find %d in array :(\n", value);
        } 
        else {
            printf("Found %d, index = %d\n", value, ans - arr);
        }
    }
}