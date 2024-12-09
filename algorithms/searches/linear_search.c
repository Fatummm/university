#include <stdio.h>

int * linear_search(int * start, int * end, int value) {
    for (int * iter = start; iter != end; ++iter) {
        if (*iter == value) return iter;
    }
    return end;
}


int main() {
    int arr[1000];
    for (int i = 0; i != 1000; ++i) {
        arr[i] = i;
    }
    int value = 123;
    for (value = 0; value != 1000; ++value) {
        int * ans = linear_search(arr, arr + 1000, value);
        if (ans == arr + 1000) {
            printf("Couldn't find %d in array :(\n", value);
        } 
        else {
            printf("Found %d, index = %d\n", value, ans - arr);
        }
    }
    
}