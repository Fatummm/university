#include <stdio.h>

int * binary_search(int * start, int * end, int value) {
    int l = 0, r = end - start, mid = 0;
    while (r >= l) {
        mid = (r + l) / 2;
        if (start[mid] < value) {
            l = mid + 1;
        }
        else if (start[mid] > value) {
            r = mid - 1;
        }
        else {
            return start + mid;
        }
    }
    
    return end;
}

int main() {
    int arr[1000];
    for (int i = 0; i != 1000; ++i) {
        arr[i] = i;
    }
    for (int value = 0; value != 1000; ++value) {
        int * ans = binary_search(arr, arr + 1000, value);
        if (ans == arr + 1000) {
            printf("Couldn't find %d in array :(\n", value);
        } 
        else {
            printf("Found %d, index = %d\n", value, ans - arr);
        }
    }
    
}