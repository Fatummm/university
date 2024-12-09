#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_arr(int * start, int size) {
    for (int * it = start; it != start + size; ++it) {
        printf("%d ", *it);
    }
}

void swap(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int * choosing_pivo(int * start, int * end) {
    return start + (rand() % (end - start)); // выбор на рандом
    //return (end - 1); // По Ломуто
    //return start; // По Хоару
}

int * lomuto_partition(int * start, int * end) {
    int * pivo = choosing_pivo(start, end);
    swap(pivo, end - 1);
    pivo = end - 1;
    int i = 0;
    for (int * it = start; it != end; ++it) {
        if (*it <= *pivo) {
            swap(it, (start + i));
            ++i;
        }
    }
    return start + i - 1;
}

int * hoar_partition(int * start, int * end) {
    int * pivo = choosing_pivo(start, end);
    swap(pivo, start);
    pivo = start;
    int i = -1, j = end - start;
    while (1) {
        do {
            ++i;
        } while (*(start + i) <= *pivo);

        do {
            --j;
        } while (*(start + j) > *pivo);
        if (i >= j) break;
        swap(start + i, start + j);
        
    }
    swap(pivo, start + j);
    return start + j;
}

void quick_sort(int * start, int * end) {
    if (end - start <= 1) return;
    int * mid = hoar_partition(start, end);
    quick_sort(start, mid);
    quick_sort(mid + 1, end);
}

int main() {
    srand(time(NULL));
    printf("Origin array: ");
    int arr[10];
    for (int i = 0; i != 10; ++i) {
        arr[i] = rand() % 101 - 50;
    }
    print_arr(arr, 12);
    printf("\n");
    quick_sort(arr, arr + 12);
    printf("Resulting array: ");
    print_arr(arr, 12);
    printf("\n");
}