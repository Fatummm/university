#include <stdio.h>
static int count = 0;
int * interpolation_search(int * start, int * end, int value) {
    int r = end - start - 1, l = 0, pos;
    while (r >= l) {
        pos = l + (double)(r - l) / (start[r] - start[l]) * (value - start[l]);
        if (start[pos] > value) l = pos - 1;
        else if (start[pos] < value) r = pos + 1;
        else return start + pos;
    }
    return end;
}

int main() {
    int arr[1000];
    for (int i = 0; i != 1000; ++i) {
        arr[i] = i;
    }
    for (int value = 0; value != 1000; ++value) {
        int * ans = interpolation_search(arr, arr + 1000, value);
        if (ans == arr + 1000) {
            printf("Couldn't find %d in array :(\n", value);
        } 
        else {
            printf("%d", value, ans - arr);
        }
    }
}