#include <stdio.h>
#include <stdlib.h>

double max(int a, int b) {
    return (a > b) ? a : b;
}

double min(int a, int b) {
    return (a < b) ? a : b;
}

void sort(double * start, double * end) {
    for (double * it1 = start + 1; it1 != end; ++it1) {
        double * iter = it1;
        for (double * it2 = it1 - 1; it2 >= start; --it2) {
            if (*iter < *it2) {
                double tmp = *iter;
                *iter = *it2;
                *it2 = tmp;
                iter = it2;
            }
        }
    }
}


void bucket_sort(double * start, double * end, int k) {
    double mn = 1e5, mx = -1e5;
    for (double * it = start; it != end; ++it) {
        mn = min(mn, *it);
        mx = max(mx, *it);
    }
    double range = mx - mn + 1;
    
    double ** buckets = (double **) malloc(k * sizeof(double *)); // каждая корзина в начале хранит количество элементов.
    for (int i = 0; i != k; ++i) {
        *(buckets + i) = (double *) malloc((end - start + 1) * sizeof(double));
        for (int j = 0; j != end - start + 1; ++j) {
            *(*(buckets + i) + j) = 0;
        }
    }
    for (double * it = start; it != end; ++it) {
        int index = (*it - mn) / ((double)range / k);
        
        buckets[index][0]++;
        buckets[index][(int)buckets[index][0]] = *it;
        
    }
    
    for (int i = 0; i != k; ++i) {
        sort(&buckets[i][1], &(buckets[i][1 + (int)buckets[i][0]]));
    }
    double *it = start;
    while (it != end) {
        for (int i = 0; i != k; ++i) {
            for (int j = 0; j != buckets[i][0]; ++j) {
                *it = buckets[i][j + 1];
                it++;
            }
        }
    }
    for (int i = 0; i != k; ++i) {
        free(*(buckets + i));
    }
    free(buckets);
}

int main() {
    double arr[] = {2, 3, 2.4, 22, 6, 3, 0.4, -3};
    bucket_sort(arr, arr + 8, 3);
    for (int i = 0; i != 8; ++i) {
        printf("%f ", arr[i]);
    }
}