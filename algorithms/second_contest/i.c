#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float min(float a, float b) {
    return (a > b) ? b : a;
}

float max(float a, float b) {
    return (a < b) ? b : a;
}

typedef struct {
    float arr[10000];
    int size;
} Bucket;

void sort_bucket(float * start, float * end) {
    int size = end - start;
    for (int i = 1; i != size; ++i) {
        for (int j = i; j != 0; --j) {
            if (start[j] < start[j - 1]) {
                float tmp = start[j];
                start[j] = start[j - 1];
                start[j - 1] = tmp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int n; scanf("%d", &n);
    //int n = 10000;
    
    float input[10000];
    float mn = 1000000, mx = 0;
    for (int i = 0; i != n; ++i) {
        scanf("%f", &input[i]);
        //input[i] = 3;//rand() % 1000000;
        mn = min(mn, input[i]);
        mx = max(mx, input[i]);
    }
    int vedro_count = (mx == mn) ? 1 : n * 2;
    if (n == 2) vedro_count = 2;
    Bucket * buckets = (Bucket *) malloc (vedro_count * sizeof(Bucket));
    for (int i = 0; i != vedro_count; ++i) {
        for (int j = 0;j != 1000; ++j) {
            buckets[i].arr[j] = 0;
        }
        buckets[i].size = 0;
    }
    printf("Initial array:\n");
    for (int i = 0; i != n; ++i) {
        if (i != 0) printf(" ");
        printf("%.2f", input[i]);
    }
    printf("\n\n");
    float b_len = (mx == mn) ? 1 : (mx - mn) / (vedro_count);
    int b_number;
    for (int i = 0; i != n; ++i) {
        if ((input[i] - mn) / b_len == vedro_count) b_number = vedro_count - 1;
        //else if ((int)((input[i] - mn) / b_len) * b_len == (input[i] - mn) && (input[i] - mn) / b_len != 0) b_number = (input[i] - mn) / b_len - 1;
        else b_number = (input[i] - mn) / b_len;
        b_number = min(b_number, vedro_count - 1);
        buckets[b_number].arr[buckets[b_number].size] = input[i];
        buckets[b_number].size++;
    }
    int index = 0;
    for (int i = 0; i != vedro_count; ++i) {
        if (buckets[i].size == 0) continue;
        printf("Bucket:\n");
        for (int j = 0; j != buckets[i].size; ++j) {
            if (j != 0) printf(" ");
            printf("%.2f", buckets[i].arr[j]);
        }
        printf("\n");
        if (buckets[i].size > 1) sort_bucket(buckets[i].arr, buckets[i].arr + buckets[i].size);
        printf("Sorted bucket:\n");
        for (int j = 0; j != buckets[i].size; ++j) {
            if (j != 0) printf(" ");
            printf("%.2f", buckets[i].arr[j]);
            input[index] = buckets[i].arr[j];
            index++;
        }
        printf("\n\n");
    }
    printf("Final array:\n");
    for (int i = 0; i != n; ++i) {
        if (i != 0) printf(" ");
        printf("%.2f", input[i]);
    }
    free(buckets);
}